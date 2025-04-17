class Controller:
    def __init__(self, model, view):
        self.model = model
        self.view = view

    def perform_search(self, pet_name, birth_date, last_visit, vet_name, diagnosis):
        found_pets = self.model.search(pet_name, birth_date, last_visit, vet_name, diagnosis)
        self.view.update_result_tree(found_pets)
        if not found_pets:
            self.view.show_message('Ошибка', 'Питомецы не были найдены')

    def perform_deleting(self, pet_name, birth_date, last_visit, vet_name, diagnosis):
        message, deleted_pets = self.model.deleting(pet_name, birth_date, last_visit, vet_name, diagnosis)
        self.view.show_message('Сообщение', f'{message}')
        remaining_pets = [
            pet for pet in self.model.records
            if not (pet['pet_name'] == pet_name and pet['birth_date'] == birth_date) and
               not (pet['last_visit'] == last_visit and pet['vet_name'] == vet_name) and
               not (diagnosis.lower() in pet['diagnosis'].lower())
        ]
        self.view.update_treeview(remaining_pets)

    def perform_add(self, pet_name, birth_date, last_visit, vet_name, diagnosis):
        if all([pet_name, birth_date, last_visit, vet_name, diagnosis]):
            self.model.add_record(pet_name, birth_date, last_visit, vet_name, diagnosis)
            self.view.update_treeview(self.model.records)
            self.view.show_message("Успех", "Питомец добавлен!")
        else:
            self.view.show_message("Ошибка", "Пожалуйста, заполните все поля.")

    def save_pet_data(self):
        file_path = self.view.save_data()
        if file_path:
            self.model.save_to_xml(file_path)
            self.view.show_message("Успех", "Данные успешно сохранены!")

    def load_from_xml(self):
        file_path = self.view.load_data()
        if file_path:
            self.model.load_from_xml(file_path)
            self.view.current_page = 1
            self.view.update_treeview(self.model.records)
            self.view.update_page_info()
            self.view.show_message("Успех", "Данные успешно загружены!")
