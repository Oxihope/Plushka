import unittest
from package import Package
from notification import Notification
from human import Human
from postoffice import PostOffice

class TestPostOfficeSystem(unittest.TestCase):

    def setUp(self):
        PostOffice._id_counter = 0
        Human._id_counter = 0
        Package._id_counter = 0
        Notification.id_counter = 0

        self.human1 = Human("Alice")
        self.human2 = Human("Bob")

        self.po1 = PostOffice("PO1", True)
        self.po2 = PostOffice("PO2", True)

        self.package = Package("Book")

    def test_post_office_to_dict_and_from_dict(self):
        d = self.po1.to_dict()
        po_restored = PostOffice.from_dict(d)
        self.assertEqual(po_restored.id, self.po1.id)
        self.assertEqual(po_restored.name, self.po1.name)
        self.assertEqual(po_restored.condition, self.po1.condition)

    def test_human_to_dict_and_from_dict(self):
        d = self.human1.to_dict()
        restored = Human.from_dict(d)
        self.assertEqual(restored.name, self.human1.name)
        self.assertEqual(restored.id, self.human1.id)

    def test_package_to_dict_and_from_dict(self):
        d = self.package.to_dict()
        restored = Package.from_dict(d)
        self.assertEqual(restored.text, self.package.text)
        self.assertEqual(restored.id, self.package.id)

    def test_notification_to_dict_and_from_dict(self):
        notif = Notification(self.po1)
        d = notif.to_dict()
        restored = Notification.from_dict(d)
        self.assertEqual(restored.id, notif.id)

    def test_send_package(self):
        self.human1.package_list.append(self.package)
        self.human1.send_package(self.package, self.human2, self.po1, self.po2)
        self.assertEqual(self.package.human_sender, self.human1)
        self.assertEqual(self.package.human_taker, self.human2)
        self.assertIn(self.package, self.po1.to_sent_package_list)
        self.assertNotIn(self.package, self.human1.package_list)

    def test_notify_taker(self):
        self.po1.notify_taker(self.human2)
        self.assertEqual(len(self.human2.notification_list), 1)
        self.assertEqual(self.human2.notification_list[0].post_office, self.po1)

    def test_send_all_packages1(self):
        self.human1.package_list.append(self.package)
        self.human1.send_package(self.package, self.human2, self.po1, self.po2)
        success = self.po1.send_all_packages()
        self.assertTrue(success)
        self.assertIn(self.package, self.po2.received_package_list)

    def test_send_all_packages2(self):
        package = Package("Book")
        human3 = Human("Peter")
        human3.package_list.append(package)
        human4 = Human("Hanna")
        post_office1 = PostOffice("PO1",True)
        post_office2 = PostOffice("PO2",False)
        human3.send_package(package,human4,post_office1,post_office2)
        success = post_office1.send_all_packages()
        self.assertFalse(success)

    def test_send_all_packages3(self):
        package = Package("Book")
        human3 = Human("Peter")
        human3.package_list.append(package)
        human4 = Human("Hanna")
        post_office1 = PostOffice("PO1",False)
        post_office2 = PostOffice("PO2",True)
        human3.send_package(package,human4,post_office1,post_office2)
        success = post_office1.send_all_packages()
        self.assertFalse(success)

    def test_take_package_from_post_office(self):
        self.human1.package_list.append(self.package)
        self.human1.send_package(self.package, self.human2, self.po1, self.po2)
        self.po1.send_all_packages()
        notif = Notification(self.po2)
        self.human2.take_notification(notif)
        success = self.human2.take_package_from_post_office(notif)
        self.assertTrue(success)
        self.assertIn(self.package, self.human2.package_list)
        self.assertEqual(len(self.human2.notification_list), 0)

    def test_take_package_from_post_office2(self):
        package1 = Package("Book1")
        package2 = Package("Book2")
        human3 = Human("Peter")
        human3.package_list.append(package1)
        human3.package_list.append(package2)
        human4 = Human("Hanna")
        human5 = Human("Bob")
        post_office1 = PostOffice("PO1",True)
        post_office2 = PostOffice("PO2",True)
        human3.send_package(package1,human4,post_office1,post_office2)
        human3.send_package(package2,human5,post_office1,post_office2)
        post_office1.send_all_packages()
        notification = Notification(post_office2)
        success = human4.take_package_from_post_office(notification)
        self.assertTrue(success)

    def test_post_office_technical_service(self):
        self.po1.condition = "Error"
        self.po1.technical_service()
        self.assertEqual(self.po1.condition, "Correct")

if __name__ == "__main__":
    unittest.main()
