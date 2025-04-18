# Лабораторная работа №2

В рамках лабораторной работы №2 была разработана программная система, которая предназначена для управления данными о питомцах с помощью графического интерфейса и XML файлов.

## Описание функционала

### Главное окно

На главном окне приложения представлена таблица со всей информацией о питомцах, оконное меню с возможными действиями над питомцами и панель с перелистыванием страниц и выбором, сколько записей будет на странице:
> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/main_window.png)

Пример изменения количества отображаемых записей на странице:

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/changing_amount.png)


### Взаимодействие с файлами

Можно загрузить данные из уже существующего XML файла:

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/uploading.png)


Также можно сохранить текущие данные из приложения в XML файл:

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/saving.png)


### Добавление питомца

Можно добавить запись о питомце с помощью отдельного окна, после нажатия на кнопку "Добавить":

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/adding.png)

При правильном введении данных запись будет отображаться в главном окне:

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/sucess_add.png)

### Поиск питомцев

Представлено 3 способа поиска питомца: 
- по имени питомца и дате рождения;
- по дате последнего приема и ФИО ветеринара;
- по фразе из диагноза

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/finding.png)

После нажатия на кнопку "Поиск" в данном окне выводятся все питомцы, которые удовлетворяют критериям поиска:

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/find_result.png)

### Удаление питомцев

Удаление записей о питомцах возможно по тем же критериям, что и поиск:
- по имени питомца и дате рождения;
- по дате последнего приема и ФИО ветеринара;
- по фразе из диагноза

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/deleting.png)

После нажатия на кнопку "Удалить" в данном окне появится сообщение о том, сколько записей было удалено, сразу же после этого данные питомцев, соответствующие одному из критериев, исчезнут из главного окна

> ![image](https://github.com/viktoriaDEVV/PPOIS/blob/master/2sem/lab2/images/deleting_amount.png)
