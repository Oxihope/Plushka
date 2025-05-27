#postoffice
from typing import TYPE_CHECKING
from typing import List

if TYPE_CHECKING:
    from package import Package
    from notification import Notification
    from human import Human

from notification import Notification

class PostOffice:
    condition_list = {
        "Correct": True,
        "Error": False
    }

    _id_counter = 0

    def __init__(
            self, 
            name: str, 
            condition: str
    ) -> None:
        self.id = PostOffice._id_counter
        PostOffice._id_counter += 1

        self.name: str = name
        self.condition: str = "Correct" if condition else "Error"
        self.received_package_list: List["Package"] = []
        self.to_sent_package_list: List["Package"] = []

    def to_dict(
            self
    ) -> dict:
        return {
            "id": self.id,
            "Name": self.name,
            "Condition": self.condition,
            "Recieved_package_list_ids": [package.id for package in self.received_package_list],
            "To_be_sented_package_list_ids": [package.id for package in self.to_sent_package_list],
            "Recieved_package_list_objects": [package.to_dict() for package in self.received_package_list],
            "To_be_sented_package_list_objects": [package.to_dict() for package in self.to_sent_package_list]
        }
    
    @staticmethod
    def from_dict(
        data: dict
    ) -> "PostOffice":
        obj = PostOffice(data["Name"], PostOffice.condition_list[data["Condition"]])
        obj.id = data["id"]
        if PostOffice._id_counter <= obj.id:
            PostOffice._id_counter = obj.id +1
        return obj

    #Сортировать список полученных посылок
    def sort_received_package_list(
            self
    ) -> None:
        self.received_package_list.sort(key=lambda package: package.text)

    #Сортировать список посылок необходимых к отправлению
    def sort_to_sent_package_list(
            self
    ) -> None:
        self.to_sent_package_list.sort(key=lambda package: package.text)

    #Операция технического обслуживания
    def technical_service(
            self
    ) -> None:
        self.sort_received_package_list()
        self.sort_to_sent_package_list()
        self.condition = "Correct"
    
    #Операция проверки состояния почтомата
    def check_correct_working(
            self
    ) -> bool:
        return PostOffice.condition_list[self.condition]

    #Принять посылку от отправителя
    def take_package_from_sender(
            self, 
            package: "Package"
    ) -> None:
        self.to_sent_package_list.append(package)

    #Уведомить получателя
    def notify_taker(
            self, 
            human_taker: "Human"
    ) -> None:
        notification = Notification(self)
        human_taker.take_notification(notification)

    #Принять посылку из почтомата
    def take_package_from_post_office(
            self, 
            package: "Package"
    ) -> None:
        self.received_package_list.append(package)
        self.notify_taker(package.human_taker)

    # Разослать все посылки
    def send_all_packages(
            self
    ) -> bool:
        correct_working_first_post_office = True
        if self.check_correct_working():
            correct_working_second_post_office = True
            new_to_sent_package_list = []
            for package in self.to_sent_package_list:
                if (package.post_office_to.check_correct_working()):
                    package.post_office_to.take_package_from_post_office(package)
                else:
                    new_to_sent_package_list.append(package)
                    correct_working_second_post_office = False
            self.to_sent_package_list = new_to_sent_package_list
            if not correct_working_second_post_office:
                self.condition = "Error"
        else:
            correct_working_first_post_office = False
        
        return correct_working_first_post_office and correct_working_second_post_office
    
    #Отдать посылки получателю
    def get_package_to_taker(
            self, 
            human_taker: "Human"
    ) -> List["Package"]:
        package_list = []
        new_received_package_list = []
        for package in self.received_package_list:
            if package.human_taker == human_taker:
                package_list.append(package)
            else:
                new_received_package_list.append(package)
        self.received_package_list = new_received_package_list
        return package_list