#human
from typing import TYPE_CHECKING
from typing import List

if TYPE_CHECKING:
    from notification import Notification
    from package import Package
    from postoffice import PostOffice

class Human:
    _id_counter = 0

    def __init__(
            self, 
            name: str
    ) -> None: 
        self.id = Human._id_counter
        Human._id_counter += 1

        self.name: str = name
        self.notification_list: List["Notification"] = []
        self.package_list: List["Package"] = []

    def to_dict(
            self
    ) -> dict:
        return {
            "id": self.id,
            "Name": self.name,
            "Notification_list_objects": [notification.to_dict() for notification in self.notification_list],
            "Package_list_objects": [package.to_dict() for package in self.package_list]
        }
    
    @staticmethod
    def from_dict(
        data: dict
    ) -> "Human":
        obj = Human(data["Name"])
        obj.id = data["id"]
        if Human._id_counter <= obj.id:
            Human._id_counter = obj.id + 1
        return obj
    
    #Отправить посылку
    def send_package(
            self, 
            package: "Package", 
            human_taker: "Human", 
            post_office_from: "PostOffice", 
            post_office_to: "PostOffice"
    ) -> None: 
        package.human_sender = self
        package.human_taker = human_taker
        package.post_office_from = post_office_from
        package.post_office_to = post_office_to
        post_office_from.take_package_from_sender(package)
        self.package_list.remove(package)

    #Принять уведомление
    def take_notification(
            self, 
            notification: "Notification"
    ) -> None:
        self.notification_list.append(notification)

    #Получить посылку из почтомата по уведомлению
    def take_package_from_post_office(
            self, 
            notification: "Notification"
    ) -> bool:
        if (notification.post_office.check_correct_working()):
            taken_packages = notification.post_office.get_package_to_taker(self)
            self.notification_list = [n for n in self.notification_list if n.post_office != notification.post_office]
            self.package_list.extend(taken_packages)
            return True
        else:
            return False