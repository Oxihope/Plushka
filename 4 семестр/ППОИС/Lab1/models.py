from typing import List

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


class Package:
    _id_counter = 0

    def __init__(
            self, 
            text: str
    ) -> None:
        self.id = Package._id_counter
        Package._id_counter += 1

        self.text: str = text
        self.human_sender: "Human" = None
        self.human_taker: "Human" = None
        self.post_office_from: "PostOffice" = None
        self.post_office_to: "PostOffice" = None

    def to_dict(
            self
    ) -> dict:
        return {
            "id": self.id,
            "Text": self.text,
            "Human_sender_id": self.human_sender.id if self.human_sender else None,
            "Human_taker_id": self.human_taker.id if self.human_taker else None,
            "Post_office_from_id": self.post_office_from.id if self.post_office_from else None,
            "Post_office_to_id": self.post_office_to.id if self.post_office_to else None
        }
    
    @staticmethod
    def from_dict(
        data: dict
    ) -> "Package":
        obj = Package(data["Text"])
        obj.id = data["id"]
        return obj  


class Notification:
    id_counter = 0
    def __init__(
            self,
            post_office: "PostOffice" = None
    ) -> None:
        self.id = Notification.id_counter
        Notification.id_counter += 1

        self.post_office: "PostOffice" = post_office

    def to_dict(
            self
    ) -> dict:
        return {
            "id": self.id,
            "Post_office_id": self.post_office.id
        }
    
    @staticmethod
    def from_dict(
        data: dict
    ) -> "Notification":
        obj = Notification()
        obj.id = data["id"]
        return obj
    
