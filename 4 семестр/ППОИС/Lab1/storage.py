import json
import os

from typing import TYPE_CHECKING
from typing import List

if TYPE_CHECKING:
    import models as m

import models as m

class Storage:
    def __init__(self, human_list = [], post_office_list = [], case_dict = {}):
        self.human_list: List["m.Human"] = human_list
        self.post_office_list: List["m.PostOffice"] = post_office_list
        self.case_dict: dict = case_dict

    def save_all(self, filename: str = "data.json") -> None:
        data = {
            "human_list": [human.to_dict() for human in self.human_list],
            "post_office_list": [post_office.to_dict() for post_office in self.post_office_list],
            "case_dict": self.case_dict
        }
        with open(filename, "w", encoding = "utf-8") as file:
            json.dump(data, file, indent = 4)

    def load_all(self, filename: str = "data.json") -> None:
        if not os.path.exists(filename):
            self.human_list = [] 
            self.post_office_list = [] 
            self.case_dict = {
                "main_choose": "",
                "human_choose": "",
                "human_operation_choose": "",
                "post_office_choose": "",
                "package_choose": "",
                "human_taker_choose": "",
                "first_post_office_choose": "",
                "second_post_office_choose": "",
                "notification_choose": ""
                }
            return

        with open(filename, "r", encoding = "utf-8") as file:
            data = json.load(file)

        human_list = [m.Human.from_dict(human) for human in data["human_list"]]
        post_office_list = [m.PostOffice.from_dict(post_office) for post_office in data["post_office_list"]]

        human_dict_id = {human.id: human for human in human_list}
        post_office_dict_id = {post_office.id: post_office for post_office in post_office_list}
        package_dict_id = {}
        notification_dict_id = {}

        for human_data in data["human_list"]:
            human = human_dict_id[human_data["id"]]
            human.package_list = []
            human.notification_list = []

            for package_data in human_data.get("Package_list_objects", []):
                package = m.Package.from_dict(package_data)
                package.human_sender = human_dict_id.get(package_data["Human_sender_id"])
                package.human_taker = human_dict_id.get(package_data["Human_taker_id"])
                package.post_office_from = post_office_dict_id.get(package_data["Post_office_from_id"])
                package.post_office_to = post_office_dict_id.get(package_data["Post_office_to_id"])
                package_dict_id[package.id] = package
                human.package_list.append(package)

            for notification_data in human_data.get("Notification_list_objects", []):
                notification = m.Notification.from_dict(notification_data)
                notification.post_office = post_office_dict_id.get(notification_data["Post_office_id"])
                notification_dict_id[notification.id] = notification
                human.notification_list.append(notification)
    
        for post_office_data in data["post_office_list"]:
            post_office = post_office_dict_id[post_office_data["id"]]
            post_office.received_package_list = []
            post_office.to_sent_package_list = []

            for package_data in post_office_data.get("Recieved_package_list_objects", []):
                package = m.Package.from_dict(package_data)
                package.human_sender = human_dict_id.get(package_data["Human_sender_id"])
                package.human_taker = human_dict_id.get(package_data["Human_taker_id"])
                package.post_office_from = post_office_dict_id.get(package_data["Post_office_from_id"])
                package.post_office_to = post_office_dict_id.get(package_data["Post_office_to_id"])
                package_dict_id[package.id] = package
                post_office.received_package_list.append(package)

            for package_data in post_office_data.get("To_be_sented_package_list_objects", []):
                package = m.Package.from_dict(package_data)
                package.human_sender = human_dict_id.get(package_data["Human_sender_id"])
                package.human_taker = human_dict_id.get(package_data["Human_taker_id"])
                package.post_office_from = post_office_dict_id.get(package_data["Post_office_from_id"])
                package.post_office_to = post_office_dict_id.get(package_data["Post_office_to_id"])
                package_dict_id[package.id] = package
                post_office.to_sent_package_list.append(package)

        case_dict = data.get("case_dict", {})
        self.human_list = human_list
        self.post_office_list = post_office_list
        self.case_dict = case_dict