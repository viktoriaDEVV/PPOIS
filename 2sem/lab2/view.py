from tkinter import *
from tkinter import messagebox, ttk, filedialog, font
from controller import Controller
from tkcalendar import DateEntry


class View:
    def __init__(self, root, controller):
        self.root = root
        self.current_page = 1
        self.records_per_page = 10
        self.controller = controller

        self.root.title("Данные о питомцах")
        self.root.geometry('1000x450')
        self.root.configure(bg="#f0f0f0")
        self.root.iconphoto(True, PhotoImage(file='images/icon.png'))
        self.model = self.controller.model
        default_font = font.nametofont("TkDefaultFont")
        default_font.configure(size=10)

        self.root.option_add("*Font", default_font)
        self.create_main_window()

    def create_main_window(self):
        toolbar = Frame(self.root, bg="#d9d9d9", padx=5, pady=5)
        toolbar.pack(side=TOP, fill=X)

        for text, cmd in [("Добавить", self.add_pet),
                          ("Сохранить", self.controller.save_pet_data),
                          ("Загрузить", self.controller.load_from_xml),
                          ("Поиск", self.open_search_window),
                          ("Удалить", self.open_deleting_window)]:
            btn = Button(toolbar, text=text, command=cmd, bg="#e6e6e6", relief="groove")
            btn.pack(side=LEFT, padx=4, pady=4)

        style = ttk.Style()
        style.configure("Treeview.Heading", font=('Arial', 10, 'bold'))
        style.configure("Treeview", rowheight=25, font=('Arial', 10))

        self.tree = ttk.Treeview(self.root,
                                 columns=("Имя", "Дата рождения", "Дата последнего приема", "Ветеринар", "Диагноз"),
                                 show='headings', style="Treeview")
        self.tree.heading('Имя', text='Имя питомца')
        self.tree.heading("Дата рождения", text="Дата рождения")
        self.tree.heading("Дата последнего приема", text="Дата последнего приема")
        self.tree.heading("Ветеринар", text="ФИО ветеринара")
        self.tree.heading("Диагноз", text="Диагноз")
        self.tree.pack(fill=BOTH, expand=1)

        self.page_info = Label(self.root, text="")
        self.page_info.pack(side=TOP)

        buttons_frame = Frame(self.root)
        buttons_frame.pack(side=TOP, fill=X)

        self.first_button = Button(buttons_frame, text="<< Первая", command=self.first_page)
        self.first_button.pack(side=LEFT)

        self.prev_button = Button(buttons_frame, text="< Предыдущая", command=self.prev_page)
        self.prev_button.pack(side=LEFT)

        self.next_button = Button(buttons_frame, text="Следующая >", command=self.next_page)
        self.next_button.pack(side=LEFT)

        self.last_button = Button(buttons_frame, text="Последняя >>", command=self.last_page)
        self.last_button.pack(side=LEFT)

        self.records_label = Label(buttons_frame, text="Записи на странице: ")
        self.records_label.pack(side=LEFT)

        self.records_per_page_entry = Spinbox(buttons_frame, from_=1, to=100, command=self.update_records_per_page)
        self.records_per_page_entry.pack(side=LEFT)

        self.update_page_info()

    def update_page_info(self):
        all_records = self.model.records
        total_records = len(all_records)
        total_pages = (total_records + self.records_per_page - 1) // self.records_per_page
        self.page_info.config(text=f"Страница {self.current_page} из {total_pages}, всего записей: {total_records}")

        self.first_button.config(state="normal" if self.current_page > 1 else "disabled")
        self.prev_button.config(state="normal" if self.current_page > 1 else "disabled")
        self.next_button.config(state="normal" if self.current_page < total_pages else "disabled")
        self.last_button.config(state="normal" if self.current_page < total_pages else "disabled")

    def first_page(self):
        if self.current_page > 1:
            self.current_page = 1
            self.update_treeview()

    def last_page(self):
        total_records = len(self.model.records)
        total_pages = (total_records + self.records_per_page - 1) // self.records_per_page
        if self.current_page < total_pages:
            self.current_page = total_pages
            self.update_treeview()

    def prev_page(self):
        if self.current_page > 1:
            self.current_page -= 1
            self.update_treeview()

    def next_page(self):
        total_records = len(self.model.records)
        total_pages = (total_records + self.records_per_page - 1) // self.records_per_page
        if self.current_page < total_pages:
            self.current_page += 1
            self.update_treeview()

    def update_records_per_page(self):
        self.records_per_page = int(self.records_per_page_entry.get())
        self.current_page = 1
        self.update_treeview()

    def add_pet(self):
        dialog = Toplevel(self.root)
        dialog.title("Добавить питомца")
        dialog.geometry('350x150')

        # Поля ввода
        Label(dialog, text="Имя питомца:").grid(row=0, column=0)
        pet_name_entry = Entry(dialog)
        pet_name_entry.grid(row=0, column=1)

        Label(dialog, text="Дата рождения:").grid(row=1, column=0)
        birth_date_entry = DateEntry(dialog, date_pattern='dd.mm.yyyy')
        birth_date_entry.grid(row=1, column=1)

        Label(dialog, text="Дата последнего визита:").grid(row=2, column=0)
        last_visit_entry = DateEntry(dialog, date_pattern='dd.mm.yyyy')
        last_visit_entry.grid(row=2, column=1)

        Label(dialog, text="Имя ветеринара:").grid(row=3, column=0)
        vet_name_entry = Entry(dialog)
        vet_name_entry.grid(row=3, column=1)

        Label(dialog, text="Диагноз:").grid(row=4, column=0)
        diagnosis_entry = Entry(dialog)
        diagnosis_entry.grid(row=4, column=1)

        Button(dialog, text="Добавить",
               command=lambda: self.controller.perform_add(pet_name_entry.get(), birth_date_entry.get(),
                                                           last_visit_entry.get(), vet_name_entry.get(),
                                                           diagnosis_entry.get())).grid(row=5, columnspan=2)

        dialog.wait_window()

    def open_search_window(self):
        search_window = Toplevel(self.root)
        search_window.title('Поиск питомцев')
        search_window.geometry('1000x550')

        Label(search_window, text="Имя питомца:").grid(column=0, row=0, padx=5, pady=5, sticky='e')
        name_entry = Entry(search_window)
        name_entry.grid(column=1, row=0, padx=5, pady=5)

        Label(search_window, text="Дата рождения:").grid(column=0, row=1, padx=5, pady=5, sticky='e')
        birth_date_entry = DateEntry(search_window, date_pattern='dd.mm.yyyy')
        birth_date_entry.grid(column=1, row=1, padx=5, pady=5)

        Label(search_window, text='Дата последнего визита:').grid(column=2, row=0, padx=5, pady=5, sticky='e')
        visit_entry = DateEntry(search_window, date_pattern='dd.mm.yyyy')
        visit_entry.grid(column=3,  row=0, padx=5, pady=5)

        Label(search_window, text='ФИО ветеринара:').grid(column=2, row=1, padx=5, pady=5, sticky='e')
        vet_name_entry = Entry(search_window)
        vet_name_entry.grid(column=3, row=1, padx=5, pady=5)

        Label(search_window, text='Фраза из диагноза:').grid(column=4, row=0, padx=5, pady=5, sticky='e')
        diagnos_entry = Entry(search_window)
        diagnos_entry.grid(column=5, row=0, padx=5, pady=5)

        search_button = Button(search_window, text="Поиск", command=lambda: self.controller.perform_search(
            name_entry.get(), birth_date_entry.get(), visit_entry.get(), vet_name_entry.get(), diagnos_entry.get()))
        search_button.grid(row=2, column=0, columnspan=4, pady=10)

        clean_button = Button(search_window, text='Очистить результат', command=self.clean)
        clean_button.grid(row=2, column=2, columnspan=4, pady=10)

        self.results_tree = ttk.Treeview(search_window, columns=(
                            "Имя", "Дата рождения", "Дата последнего приема", "Ветеринар", "Диагноз"), show='headings')
        self.results_tree.heading('Имя', text='Имя питомца')
        self.results_tree.heading("Дата рождения", text="Дата рождения")
        self.results_tree.heading("Дата последнего приема", text="Дата последнего приема")
        self.results_tree.heading("Ветеринар", text="ФИО ветеринара")
        self.results_tree.heading("Диагноз", text="Диагноз")
        self.results_tree.grid(row=3, column=0, columnspan=6)

    def open_deleting_window(self):
        search_window = Toplevel(self.root)
        search_window.title('Удаление питомцев')

        message_var = StringVar()

        Label(search_window, text="Имя питомца:").grid(column=0, row=0, padx=5, pady=5, sticky='e')
        name_entry = Entry(search_window)
        name_entry.grid(column=1, row=0, padx=5, pady=5)

        Label(search_window, text="Дата рождения:").grid(column=0, row=1, padx=5, pady=5, sticky='e')
        birth_date_entry = DateEntry(search_window, date_pattern='dd.mm.yyyy')
        birth_date_entry.grid(column=1, row=1, padx=5, pady=5)

        Label(search_window, text='Дата последнего визита:').grid(column=2, row=0, padx=5, pady=5, sticky='e')
        visit_entry = DateEntry(search_window, date_pattern='dd.mm.yyyy')
        visit_entry.grid(column=3, row=0, padx=5, pady=5)

        Label(search_window, text='ФИО ветеринара:').grid(column=2, row=1, padx=5, pady=5, sticky='e')
        vet_name_entry = Entry(search_window)
        vet_name_entry.grid(column=3, row=1, padx=5, pady=5)

        Label(search_window, text='Фраза из диагноза:').grid(column=4, row=0, padx=5, pady=5, sticky='e')
        diagnos_entry = Entry(search_window)
        diagnos_entry.grid(column=5, row=0, padx=5, pady=5)

        search_button = Button(search_window, text="Удалить",
                               command=lambda: self.controller.perform_deleting(name_entry.get(),
                                                                                birth_date_entry.get(),
                                                                                visit_entry.get(), vet_name_entry.get(),
                                                                                diagnos_entry.get()))
        search_button.grid(row=2, column=0, columnspan=6, pady=10)

        message_label = Label(search_window, textvariable=message_var)
        message_label.grid(row=4, column=0, columnspan=6, sticky='nsew')

    def update_treeview(self, pets=None):

        if pets is None:
            all_records = self.model.records
        else:
            all_records = pets

        total_records = len(all_records)
        total_pages = (total_records + self.records_per_page - 1) // self.records_per_page

        if self.current_page > total_pages and total_pages > 0:
            self.current_page = total_pages
        elif total_pages == 0:
            self.current_page = 1

        start_index = (self.current_page - 1) * self.records_per_page
        end_index = start_index + self.records_per_page
        pets_to_display = all_records[start_index:end_index]

        self.tree.delete(*self.tree.get_children())
        for pet in pets_to_display:
            if all(key in pet for key in ('pet_name', 'birth_date', 'last_visit', 'vet_name', 'diagnosis')):
                self.tree.insert("", END, values=(pet['pet_name'], pet['birth_date'], pet['last_visit'],
                                                  pet['vet_name'], pet['diagnosis']))
            else:
                print(f"Missing keys in pet record: {pet}")

        self.update_page_info()

    def update_result_tree(self, pets):
        for pet in pets:
            self.results_tree.insert("", END, values=(pet['pet_name'], pet['birth_date'], pet['last_visit'],
                                                      pet['vet_name'], pet['diagnosis']))

    @staticmethod
    def save_data():
        file_path = filedialog.asksaveasfilename(defaultextension=".xml",
                                                 filetypes=[("XML files", "*.xml"),
                                                            ("All files", "*.*")])
        return file_path

    def clean(self):
        self.results_tree.delete(*self.results_tree.get_children())

    @staticmethod
    def show_message(title, message):
        messagebox.showinfo(title, message)

    @staticmethod
    def load_data():
        file_path = filedialog.askopenfilename(filetypes=[("XML files", "*.xml"), ("All files", "*.*")])
        return file_path
