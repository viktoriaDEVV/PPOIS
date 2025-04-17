import xml.sax


class PetHandler(xml.sax.ContentHandler):
    def __init__(self):
        super().__init__()
        self.current_data = ''
        self.pets = []
        self.current_pet = {}

    def startElement(self, tag, attributes):
        self.current_data = tag
        if tag == 'pet':
            self.current_pet = {}

    def characters(self, content):
        if self.current_data in ['pet_name', 'birth_date', 'last_visit', 'vet_name', 'diagnosis']:
            self.current_pet[self.current_data] = self.current_pet.get(self.current_data, '') + content.strip()

    def endElement(self, tag):
        if tag == 'pet':
            self.pets.append(self.current_pet)
