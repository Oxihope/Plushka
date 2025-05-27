#package
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from human import Human
    from postoffice import PostOffice

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