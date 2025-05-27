import unittest
from unittest.mock import MagicMock, mock_open, patch
import json

from storage import Storage

class TestStorage(unittest.TestCase):

    def setUp(self):
        # Создаем фейковые объекты Human и PostOffice с методом to_dict
        self.fake_human = MagicMock()
        self.fake_human.to_dict.return_value = {"id": 1, "Package_list_objects": [], "Notification_list_objects": []}
        self.fake_post_office = MagicMock()
        self.fake_post_office.to_dict.return_value = {"id": 101, "Recieved_package_list_objects": [], "To_be_sented_package_list_objects": []}
        self.storage = Storage([self.fake_human], [self.fake_post_office], {"test_key": "test_value"})

    @patch("builtins.open", new_callable=mock_open)
    @patch("json.dump")
    def test_save_all(self, mock_json_dump, mock_open_file):
        self.storage.save_all("test.json")

        mock_open_file.assert_called_once_with("test.json", "w", encoding="utf-8")
        mock_json_dump.assert_called_once()

        dumped_data = mock_json_dump.call_args[0][0]
        self.assertIn("human_list", dumped_data)
        self.assertIn("post_office_list", dumped_data)
        self.assertIn("case_dict", dumped_data)

    @patch("os.path.exists", return_value=True)
    @patch("builtins.open", new_callable=mock_open)
    @patch("json.load")
    @patch("models.Human")
    @patch("models.PostOffice")
    @patch("models.Package")
    @patch("models.Notification")
    def test_load_all(self, mock_notification, mock_package, mock_post_office, mock_human, mock_json_load, mock_open_file, mock_path_exists):
        # Подготавливаем фейковые данные
        mock_json_load.return_value = {
            "human_list": [{"id": 1}],
            "post_office_list": [{"id": 101}],
            "case_dict": {"main_choose": "1"}
        }

        # Настраиваем поведение методов from_dict
        mock_human.from_dict.return_value = MagicMock(id=1, package_list=[], notification_list=[])
        mock_post_office.from_dict.return_value = MagicMock(id=101, received_package_list=[], to_sent_package_list=[])
        
        self.storage.load_all("test.json")

        self.assertEqual(len(self.storage.human_list), 1)
        self.assertEqual(len(self.storage.post_office_list), 1)
        self.assertEqual(self.storage.case_dict["main_choose"], "1")

    @patch("os.path.exists", return_value=False)
    def test_load_all_file_not_exists(self, mock_exists):
        self.storage.load_all("nonexistent.json")

        self.assertEqual(self.storage.human_list, [])
        self.assertEqual(self.storage.post_office_list, [])
        self.assertIsInstance(self.storage.case_dict, dict)
        self.assertIn("main_choose", self.storage.case_dict)

if __name__ == "__main__":
    unittest.main()
