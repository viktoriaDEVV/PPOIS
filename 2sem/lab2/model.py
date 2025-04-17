from xml.dom import minidom
import os
from sax_parser import *


class Model:
    def __init__(self):
        self.records = []

    def search(self, pet_name, birth_date, last_visit, vet_name, diagnosis):
        filtered_pets = []
        if pet_name and birth_date:
            filtered_pets.extend(pet for pet in self.records if pet['pet_name'] == pet_name and
                                 pet['birth_date'] == birth_date)
        if last_visit and vet_name:
            filtered_pets.extend(pet for pet in self.records if pet['last_visit'] == last_visit and
                                 pet['vet_name'] == vet_name)
        if diagnosis:
            filtered_pets.extend(pet for pet in self.records if diagnosis.lower() in pet['diagnosis'].lower())
        return filtered_pets

    def deleting(self, pet_name, birth_date, last_visit, vet_name, diagnosis):
        filtered_pets = []

        if pet_name and birth_date:
            filtered_pets.extend(pet for pet in self.records if pet['pet_name'] == pet_name and
                                 pet['birth_date'] == birth_date)
        if last_visit and vet_name:
            filtered_pets.extend(pet for pet in self.records if pet['last_visit'] == last_visit and
                                 pet['vet_name'] == vet_name)
        if diagnosis:
            filtered_pets.extend(pet for pet in self.records if diagnosis.lower() in pet['diagnosis'].lower())
        deleted_count = len(filtered_pets)
        if deleted_count > 0:
            return f'Удалено {deleted_count} записей', filtered_pets
        else:
            return 'Записи не были найдены', filtered_pets

    def add_record(self, pet_name, birth_date, last_visit, vet_name, diagnosis):
        record = {
            'pet_name': pet_name,
            'birth_date': birth_date,
            'last_visit': last_visit,
            'vet_name': vet_name,
            'diagnosis': diagnosis
        }
        self.records.append(record)

    def save_to_xml(self, file_path):
        if os.path.exists(file_path):
            doc = minidom.parse(file_path)
            root = doc.documentElement
        else:
            doc = minidom.Document()
            root = doc.createElement('pets')
            doc.appendChild(root)

        for record in self.records:
            pet_element = doc.createElement('pet')

            for key, value in record.items():
                element = doc.createElement(key)
                text_node = doc.createTextNode(value)
                element.appendChild(text_node)
                pet_element.appendChild(element)

            root.appendChild(pet_element)

        with open(file_path, 'w', encoding='utf-8') as file:
            file.write(doc.toprettyxml(indent="  "))

    def load_from_xml(self, file_path):
        handler = PetHandler()
        parser = xml.sax.make_parser()
        parser.setContentHandler(handler)
        try:
            parser.parse(file_path)
            self.records = handler.pets
        except Exception as e:
            print(f"Error loading data from {file_path}: {e}")
