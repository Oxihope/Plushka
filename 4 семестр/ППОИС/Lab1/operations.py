from typing import TYPE_CHECKING
from typing import List
import models as m
import storage as s

if TYPE_CHECKING:
    import models as m
    import storage as s

class CLI:
    def __init__(self, storage: "s.Storage") -> None:
        self.storage: "s.Storage" = storage

    @staticmethod
    def print_humans(human_list: List["m.Human"]) -> None:
        for i, human in enumerate(human_list):
            print(f"{i + 1}. {human.name}")

    @staticmethod
    def print_human_notification_list(human: "m.Human") -> None:
        if len(human.notification_list) == 0:
            print("Список уведомлений пуст")
        else:
            print(f"Список уведомлений {human.name}")
            for i, notification in enumerate(human.notification_list):
                print(f"{i+1}. Заберите посылку в {notification.post_office.name}")

    @staticmethod
    def print_human_package_list(human: "m.Human") -> None:
        if len(human.package_list) == 0:
            print("Список посылок пуст")
        else:
            print(f"Список посылок у {human.name}")
            for i, package in enumerate(human.package_list):
                print(f"{i+1}. {package.text}")
    
    def get_main_choose(self) -> str:
        main_choose = self.storage.case_dict.get("main_choose", "")
        while True:
            if not main_choose:
                print("\n=== Главное меню ===")
                print("Выберите дейтсвие")
                print("1. Выбрать человека")
                print("2. Выбрать почтомат")
                print("3. Завершить работу")
                main_choose = input()

                if not main_choose:
                    main_choose = ""
                    print("Ничего не введено")
                    continue

                self.storage.case_dict["main_choose"] = main_choose
                self.storage.save_all()
            break
        return main_choose
    
    def get_human_choose(self) -> int:
        human_choose = self.storage.case_dict.get("human_choose", "")
        while True:
            if not human_choose:
                print("\nВыберите человека")
                CLI.print_humans(self.storage.human_list)
                print(f"{len(self.storage.human_list)+1}. Создать нового человека")
                print(f"{len(self.storage.human_list)+2}. Выйти")
                human_choose = input()

                if not human_choose:
                    human_choose = ""
                    print("Ничего не введено")
                    continue

                if not human_choose.isdigit():
                    print("Ошибка. Введено не целое число.")
                    human_choose = ""
                    continue

                human_choose = int(human_choose)
                self.storage.case_dict["human_choose"] = human_choose
                self.storage.save_all()
            break
        return human_choose
    
    def get_human_operation_choose(self) -> str:
        human_operation_choose = self.storage.case_dict.get("human_operation_choose", "")
        while True:
            if not human_operation_choose:
                human_choose = self.storage.case_dict.get("human_choose")
                human_index = human_choose - 1
                human = self.storage.human_list[human_index]
                print(f"\n==Меню человека {human.name}==")
                print("Выеберите операцию")
                print("1. Вывести список уведомлений пользователя")
                print("2. Вывести список имеющихся посылок")
                print("3. Забрать посылки из почтоматов по уведомлениям")
                print("4. Отправить посылку")
                print("5. Выйти")
                human_operation_choose = input()

                if not human_operation_choose:
                    print("Ничего не введено")
                    human_operation_choose = ""
                    continue

                self.storage.case_dict["human_operation_choose"] = human_operation_choose
                self.storage.save_all()
            break
        return human_operation_choose

    def get_notification_choose(self) -> int:
        notification_choose = self.storage.case_dict.get("notification_choose", "")
        while True:
            if not notification_choose:
                human_choose = self.storage.case_dict.get("human_choose")
                human_index = human_choose - 1
                human: "m.Human"= self.storage.human_list[human_index]
                print("Выберите уведомление")
                CLI.print_human_notification_list(human)
                print(f"{len(human.notification_list)+1}. Выйти")
                notification_choose = input()

                if not notification_choose:
                    print("Ничего не введено")
                    notification_choose = ""
                    continue
        
                if not notification_choose.isdigit():
                    print("Ошибка. Введено не целое число.")
                    notification_choose = ""
                    continue

                notification_choose = int(notification_choose)
                self.storage.case_dict["notification_choose"] = notification_choose
                self.storage.save_all()
            break
        return notification_choose

    @staticmethod
    def take_package_operation(human: "m.Human", notification: "m.Notification") -> None:
        success = human.take_package_from_post_office(notification)
        if not success:
            print(f"Извините, но {notification.post_office.name} не работает")
        else:
            print("Вы забрали посылку")

    def take_package_menu(self, human: "m.Human") -> None:
        while True:
            notification_choose = self.get_notification_choose()

            match notification_choose:
                #Выбор уведомления из списка
                case n if 1 <= n <= len(human.notification_list):
                    notification_index = n-1
                
                #Выйти в выбор операции
                case n if n == len(human.notification_list) + 1:
                    self.storage.case_dict["notification_choose"] = notification_choose = ""
                    self.storage.save_all()
                    break
                 
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы списка")

                    self.storage.case_dict["notification_choose"] = notification_choose = ""
                    self.storage.save_all()
                    continue

            notification_for_take = human.notification_list[notification_index]

            CLI.take_package_operation(human, notification_for_take)
            
            self.storage.case_dict["notification_choose"] = notification_choose = ""
            self.storage.save_all()

    def get_package_choose(self) -> int:
        package_choose = self.storage.case_dict.get("package_choose", "")
        while True:
            if not package_choose:
                human_choose = self.storage.case_dict.get("human_choose")
                human_index = human_choose - 1
                human: "m.Human" = self.storage.human_list[human_index]
                print("\nВыберите посылку")
                CLI.print_human_package_list(human)
                print(f"{len(human.package_list)+1}. Создать новую посылку")
                print(f"{len(human.package_list)+2}. Выйти")
                package_choose_input = input()

                if not package_choose_input:
                    print("Ничего не введено")
                    package_choose = ""
                    continue

                if not package_choose_input.isdigit():
                    print("Ошибка. Введите число")
                    package_choose = ""
                    continue

                package_choose = int(package_choose_input)
                self.storage.case_dict["package_choose"] = package_choose
                self.storage.save_all()
            break
        return package_choose

    def get_human_taker_choose(self) -> int:
        human_taker_choose = self.storage.case_dict.get("human_taker_choose", "")
        while True:
            if not human_taker_choose:
                print("\nВыберите, кому отправить посылку")
                CLI.print_humans(self.storage.human_list)
                print(f"{len(self.storage.human_list)+1}. Выйти")
                human_taker_choose = input()

                if not human_taker_choose:
                    print("Ничего не введено")
                    human_taker_choose = ""
                    continue

                if not human_taker_choose.isdigit():
                    print("Ошибка. Введите число")
                    human_taker_choose = ""
                    continue

                human_taker_choose = int(human_taker_choose)
                self.storage.case_dict["human_taker_choose"] = human_taker_choose
                self.storage.save_all()
            break
        return human_taker_choose

    @staticmethod
    def print_post_offices(post_office_list: List["m.PostOffice"]) -> None:
        for i, post_office in enumerate(post_office_list):
            print(f"{i + 1}. {post_office.name}")

    def get_first_post_office_choose(self) -> int:
        first_post_office_choose = self.storage.case_dict.get("first_post_office_choose", "")
        while True:
            if not first_post_office_choose:
                print("\nВыберите, в какой почтомат отнести посылку")
                CLI.print_post_offices(self.storage.post_office_list)
                print(f"{len(self.storage.post_office_list)+1}. Выйти")
                first_post_office_choose = input()

                if not first_post_office_choose:
                    print("Ничего не введено")
                    first_post_office_choose = ""
                    continue

                if not first_post_office_choose.isdigit():
                    print("Ошибка. Введите число")
                    first_post_office_choose = ""
                    continue

                first_post_office_choose = int(first_post_office_choose)
                self.storage.case_dict["first_post_office_choose"] = first_post_office_choose
                self.storage.save_all()
            break
        return first_post_office_choose
    
    def get_second_post_office_choose(self) -> int:
        second_post_office_choose = self.storage.case_dict.get("second_post_office_choose", "")
        while True:
            if not second_post_office_choose:
                print("\nВыберите почтомат, куда придет посылка")
                CLI.print_post_offices(self.storage.post_office_list)
                print(f"{len(self.storage.post_office_list)+1}. Выйти")
                second_post_office_choose = input()

                if not second_post_office_choose:
                    print("Ничего не введено")
                    second_post_office_choose = ""
                    continue
            
                if not second_post_office_choose.isdigit():
                    print("Ошибка. Введите число")
                    continue
            
                second_post_office_choose = int(second_post_office_choose)
                self.storage.case_dict["second_post_office_choose"] = second_post_office_choose
                self.storage.save_all()
            break
        return second_post_office_choose

    @staticmethod
    def send_package_operation( human: "m.Human", package: "m.Package", human_taker: "m.Human", first_post_office: "m.PostOffice", second_post_office: "m.PostOffice") -> None:
        human.send_package(package,human_taker,first_post_office,second_post_office)
        print(f"Посылка получена почтоматом {first_post_office.name}")
    
    def second_post_office_menu(self, human: "m.Human", package: "m.Package", human_taker: "m.Human", first_post_office: "m.PostOffice") -> bool:
        while True:
            second_post_office_choose = self.get_second_post_office_choose()
                                                
            match second_post_office_choose:
                #Выбор второго почтомата из списка
                case n if 1 <= n <= len(self.storage.post_office_list):
                    second_post_office_index = n-1
                    
                #Выйти в выбор первого почтомата
                case n if n == len(self.storage.post_office_list) + 1:
                    self.storage.case_dict["second_post_office_choose"] = second_post_office_choose = ""
                    self.storage.save_all()
                    break
                
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы")

                    self.storage.case_dict["second_post_office_choose"] = second_post_office_choose = ""
                    self.storage.save_all()
                    continue
            
            second_post_office = self.storage.post_office_list[second_post_office_index]

            CLI.send_package_operation(human, package, human_taker, first_post_office, second_post_office)
            
            self.storage.case_dict["second_post_office_choose"] = second_post_office_choose = ""
            self.storage.save_all()
            return True
        return False

    def first_post_office_menu(self, human: "m.Human", package: "m.Package", human_taker: "m.Human") -> bool:
        while True:
            first_post_office_choose = self.get_first_post_office_choose()
                                            
            match first_post_office_choose:
                #Выбор первого почтомата из списка
                case n if 1 <= n <= len(self.storage.post_office_list):
                    first_post_office_index = n-1
                    if not self.storage.post_office_list[first_post_office_index].check_correct_working():
                        print(f"{self.storage.post_office_list[first_post_office_index].name} на данный момент не работает")
                        self.storage.case_dict["first_post_office_choose"] = first_post_office_choose = ""
                        self.storage.save_all()
                        continue
                
                #Выйти в выбор получателя
                case n if n == len(self.storage.post_office_list) + 1:
                    self.storage.case_dict["first_post_office_choose"] = first_post_office_choose = ""
                    self.storage.save_all()
                    break
                 
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы")

                    self.storage.case_dict["first_post_office_choose"] = first_post_office_choose = ""
                    self.storage.save_all()
                    continue
                                            
            first_post_office = self.storage.post_office_list[first_post_office_index]

            verification = self.second_post_office_menu(human, package, human_taker, first_post_office)
            
            self.storage.case_dict["first_post_office_choose"] = first_post_office_choose = ""
            self.storage.save_all()
            if verification:
                return True
        return False

    def human_taker_menu(self, human: "m.Human", package: "m.Package") -> None:
        while True:
            human_taker_choose = self.get_human_taker_choose()

            match human_taker_choose:
                #Выбор человека из списка
                case n if 1 <= n <= len(self.storage.human_list):
                    human_taker_index = n-1
                
                #Выйти в выбор посылки
                case n if n == len(self.storage.human_list) + 1:
                    self.storage.case_dict["human_taker_choose"] = human_taker_choose = ""
                    self.storage.save_all()
                    break
                
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы")

                    self.storage.case_dict["human_taker_choose"] = human_taker_choose = ""
                    self.storage.save_all()
                    continue
                
            human_taker = self.storage.human_list[human_taker_index]
            
            verification = self.first_post_office_menu(human, package, human_taker)

            self.storage.case_dict["human_taker_choose"] = human_taker_choose = ""
            self.storage.save_all()
            if verification:
                break

    def send_package_menu(self, human: "m.Human") -> None:
        while True:
            package_choose = self.get_package_choose()
                                    
            match package_choose:
                #Выбор посылки из списка
                case n if 1 <= n <= len(human.package_list):
                    package_index = n-1
                
                #Создание новой посылки
                case n if n == len(human.package_list) + 1:
                    print("Введите текст посылки")
                    package_text = input()

                    if not package_text:
                        print("Ничего не введено")
                        continue

                    new_package = m.Package(package_text)
                    human.package_list.append(new_package)
                    package_index = len(human.package_list)-1
                    self.storage.save_all()
                
                #Выйти в выбор операции
                case n if n == len(human.package_list) + 2:
                    self.storage.case_dict["package_choose"] = package_choose = ""
                    self.storage.save_all()
                    break
                
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы")
                    self.storage.case_dict["package_choose"] = package_choose = ""
                    self.storage.save_all()
                    continue
                
            package = human.package_list[package_index]
            
            self.human_taker_menu(human, package)

            self.storage.case_dict["package_choose"] = package_choose = ""
            self.storage.save_all()

    def human_operation_menu(self, human: "m.Human") -> None:
        while True:
            human_operation_choose = self.get_human_operation_choose()

            match human_operation_choose:
                #Вывести список уведомлений пользователя
                case "1":
                    CLI.print_human_notification_list(human)

                    self.storage.case_dict["human_operation_choose"] = human_operation_choose = ""
                    self.storage.save_all()
                            
                #Вывести список имеющихся посылок
                case "2":
                    CLI.print_human_package_list(human)

                    self.storage.case_dict["human_operation_choose"] = human_operation_choose = ""
                    self.storage.save_all()
                            
                #Забрать посылки из почтоматов по уведомлениям
                case "3":
                    self.take_package_menu(human)  

                    self.storage.case_dict["human_operation_choose"] = human_operation_choose = ""
                    self.storage.save_all()
                            
                #Отправить посылку
                case "4":
                    self.send_package_menu(human)
                                
                    self.storage.case_dict["human_operation_choose"] = human_operation_choose = ""
                    self.storage.save_all()
                            
                #Выйти в выбор человека
                case "5":
                    self.storage.case_dict["human_operation_choose"] = human_operation_choose = ""
                    self.storage.save_all()
                    break
                            
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы списка")

                    self.storage.case_dict["human_operation_choose"] = human_operation_choose = ""
                    self.storage.save_all()
                    continue
    
    def human_choose_menu(self) -> None:
        while True:
            human_choose = self.get_human_choose()
                    
            match human_choose:
                #Выбор человека из списка
                case n if 1 <= n <= len(self.storage.human_list): 
                    human_index = n - 1
                        
                #Создание нового человека
                case n if n == len(self.storage.human_list) + 1: 
                    print("Введите имя человека")
                    human_name = input()

                    if not human_name.isalpha():
                        print("Разрешено вводить только буквы")
                        continue

                    if not human_name:
                        print("Ничего не введено")
                        continue
                    
                    new_human = m.Human(human_name)
                    self.storage.human_list.append(new_human)
                    human_index = len(self.storage.human_list) - 1
                    self.storage.save_all()
                        
                #Выйти в главное меню
                case n if n == len(self.storage.human_list) + 2:
                    self.storage.case_dict["human_choose"] = human_choose = ""
                    self.storage.save_all()
                    break
                        
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы списка")

                    self.storage.case_dict["human_choose"] = human_choose = ""
                    self.storage.save_all()
                    continue

            human = self.storage.human_list[human_index]

            self.human_operation_menu(human)

            self.storage.case_dict["human_choose"] = human_choose = ""
            self.storage.save_all()

    def get_post_office_choose(self) -> int:
        post_office_choose = self.storage.case_dict.get("post_office_choose", "")
        while True:
            if not post_office_choose:
                print("\nВыберите почтомат")
                CLI.print_post_offices(self.storage.post_office_list)
                print(f"{len(self.storage.post_office_list)+1}. Создать новый почтомат")
                print(f"{len(self.storage.post_office_list)+2}. Выход")
                post_office_choose = input()

                if not post_office_choose:
                    print("Ничего не введено")
                    post_office_choose = ""
                    continue

                if not post_office_choose.isdigit():
                    print("Ошибка. Введите целое число")
                    post_office_choose = ""
                    continue
            
                post_office_choose = int(post_office_choose)
                self.storage.case_dict["post_office_choose"] = post_office_choose
                self.storage.save_all()
            break
        return post_office_choose
    
    def get_post_office_operation_choose(self) -> str:
        post_office_choose = self.storage.case_dict.get("post_office_choose")
        post_office_index = post_office_choose - 1
        post_office: "m.PostOffice" = self.storage.post_office_list[post_office_index]
        while True:
            print(f"\n==Меню почтомата {post_office.name}==")
            print("Выберите операцию")
            print("1. Вывести список посылок, которые необходимо отправить")
            print("2. Вывести список полученных посылок")
            print("3. Разослать посылки")
            print("4. Проверка состояния почтомата")
            print("5. Техническое обслуживание")
            print("6. Выход")
            post_office_operation_choose = input()

            if not post_office_operation_choose:
                print("Ошибка. Введите число")
                continue

            if not post_office_operation_choose.isdigit():
                print("Ошибка. Введите число")
                continue
            break
        return post_office_operation_choose

    def print_post_office_to_sent_package_list(post_office: "m.PostOffice") -> None:
        if len(post_office.to_sent_package_list) == 0:
            print("Список посылок, котрые почтомату необходимо отправить, пуст")
        else:
            print("Список посылок к отправлению:")
            for i, package in enumerate(post_office.to_sent_package_list):
                print(f"{i+1}. {package.text}")
    
    def print_post_office_received_package_list(post_office: "m.PostOffice") -> None:
        if len(post_office.received_package_list) == 0:
            print("Список полученных посылок пуст")
        else:
            print("Список полученных посылок:")
            for i, package in enumerate(post_office.received_package_list):
                print(f"{i+1}. {package.text}")   

    def post_office_operation_menu(self, post_office: "m.PostOffice") -> None:
        while True:
            post_office_operation_choose = self.get_post_office_operation_choose()
            
            match post_office_operation_choose:
                #Вывести список посылок, которые необходимо отправить
                case "1":
                    CLI.print_post_office_to_sent_package_list(post_office)
                    
                #Вывести список полученных посылок
                case "2":
                    CLI.print_post_office_received_package_list(post_office)
                
                #Разослать посылки
                case "3":
                    if not post_office.check_correct_working():
                        print("Извините, почтомат не работает")
                        continue
                    
                    correct_working = post_office.send_all_packages()

                    if correct_working:
                        print("Все посылки разосланы")
                    else:
                        print("Некоторые посылки не были отправлены")
                
                #Проверка состояния почтомата
                case "4":
                    if post_office.check_correct_working():
                        print("Почтомат работает исправно")
                    else:
                        print("Почтомат неисправен")
                        
                #Техническое обслуживание
                case "5":
                    post_office.technical_service()

                    print("Почтомат обслужили")
                
                #Выйти в выбор почтомата
                case "6":
                    break

    def post_office_choose_menu(self):
        while True:
            post_office_choose = self.get_post_office_choose()

            match post_office_choose:
                #Выбор почтомата из списка
                case n if 1 <= n <= len(self.storage.post_office_list):
                    post_office_index = n-1
                
                #Создание нового почтомата
                case n if n == len(self.storage.post_office_list) + 1:
                    print("Введите имя почтомата")
                    post_office_name = input()

                    if not post_office_name.isalpha():
                        print("Разрешено вводить только буквы")
                        continue

                    if not post_office_name:
                        print("Ничего не введено")
                        continue

                    while True:
                        print("Введите 0, если почтомат неисправен\nВведите 1, если почтомат исправен")
                        post_office_condition = input()

                        if not post_office_condition:
                            print("Ничего не введено")
                            continue

                        if not post_office_condition.isdigit():
                            print("Ошибка. Введено не целое число")
                            continue

                        post_office_condition = int(post_office_condition)
                        
                        if post_office_condition not in (0,1):
                            print("Ошибка. Выход за границы")
                            continue

                        break
                    
                    new_post_office = m.PostOffice(post_office_name,post_office_condition)
                    self.storage.post_office_list.append(new_post_office)
                    post_office_index = len(self.storage.post_office_list)-1
                    self.storage.save_all()
                    
                #Выйти в главное меню
                case n if n == len(self.storage.post_office_list) + 2:
                    self.storage.case_dict["post_office_choose"] = post_office_choose = ""
                    self.storage.save_all()
                    break
                
                #Выход за границы
                case _:
                    print("Неверный номер. Выход за границы")
                    
                    self.storage.case_dict["post_office_choose"] = post_office_choose = ""
                    self.storage.save_all()
                    continue
            
            post_office = self.storage.post_office_list[post_office_index]
            
            self.post_office_operation_menu(post_office)

            self.storage.case_dict["post_office_choose"] = post_office_choose = ""
            self.storage.save_all()

    def run(self):
        while True:
            main_choose = self.get_main_choose()

            match main_choose:
                case "1":
                    self.human_choose_menu()

                    self.storage.case_dict["main_choose"] = main_choose = ""
                    self.storage.save_all()
                case "2":
                    self.post_office_choose_menu()

                    self.storage.case_dict["main_choose"] = main_choose = ""
                    self.storage.save_all()
                case "3":
                    print("Выход из программы")
                    
                    self.storage.case_dict["main_choose"] = main_choose = ""
                    self.storage.save_all()
                    break
                case _:
                    print("Ошибка ввода. Выход за границы")

                    self.storage.case_dict["main_choose"] = main_choose = ""
                    self.storage.save_all()
                    continue
        
        self.storage.human_list = []
        self.storage.post_office_list = []
        self.storage.case_dict = {}
        self.storage.save_all()
