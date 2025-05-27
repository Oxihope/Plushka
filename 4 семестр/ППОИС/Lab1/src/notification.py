#notification
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from postoffice import PostOffice

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