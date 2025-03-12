from Product import Product
from ISO9001Standard import ISO9001Standard
from FDAStandard import FDAStandard
from CEStandard import CEStandard
from QualityController import QualityController
from Review import Review
from ReviewAnalyzer import ReviewAnalyzer


def main():
    controller = QualityController()
    quality_standards = {
        "1": ISO9001Standard(),
        "2": FDAStandard(),
        "3": CEStandard()
    }

    while True:
        print("""
        Меню:
        1. Добавить продукт
        2. Список продуктов
        3. Запустить производство
        4. Проверить продукт по стандарту качества
        5. Внести улучшения в продукт
        6. Выдать сертификат продукту
        7. Добавить отзыв
        8. Анализировать отзывы 
        9. Выход
        """)

        choice = input("Выберите действие: ")

        if choice == '1':
            product_name = input("Введите название продукта: ")
            product = Product(product_name)
            controller.add_product(product)
            print(f"Продукт c ID {product.product_id} добавлен.")
            print(product.__str__())

        elif choice == '2':
            list_of_products = controller.show_products()
            print("\nСписок продуктов:")
            if not list_of_products:
                print("Список продуктов пуст.")
            else:
                for product_id, name in list_of_products:
                    print(f"ID: {product_id}, Название: {name}")

        elif choice == '3':
            product_id = input("Введите ID продукта для запуска производства: ")
            product = next((p for p in controller.products if p.product_id == product_id), None)
            if product:
                controller.run_production(product)
            else:
                print(f"Продукт с ID {product_id} не найден.")

        elif choice == '4':
            print('Выберите стандарт качества:')
            for key, standard in quality_standards.items():
                print(f"{key}. {standard.standard_name}")
            standard_choice = input("Введите номер стандарта: ")

            if standard_choice in quality_standards:
                product_id = input("Введите ID продукта для проверки: ")
                controller.check_compliance(product_id, quality_standards[standard_choice])
            else:
                print("Неверный выбор стандарта.")

        elif choice == '5':
            product_id = input("Введите ID продукта для внесения улучшений: ")
            print('Выберите стандарт качества:')
            for key, standard in quality_standards.items():
                print(f"{key}. {standard.standard_name}")
            standard_choice = input("Введите номер стандарта: ")

            if standard_choice in quality_standards:
                controller.improve_product(product_id, quality_standards[standard_choice])
            else:
                print("Неверный выбор стандарта.")

        elif choice == '6':
            product_id = input("Введите ID продукта для выдачи сертификата: ")
            print('Выберите стандарт качества:')
            for key, standard in quality_standards.items():
                print(f"{key}. {standard.standard_name}")
            standard_choice = input("Введите номер стандарта: ")
            if standard_choice in quality_standards:
                controller.certify_product(product_id, quality_standards[standard_choice])
            else:
                print("Неверный выбор стандарта.")

        elif choice == '7':
            product_id = input("Введите ID продукта для добавления отзыва: ")
            while True:
                try:
                    author = input("Введите имя автора: ")
                    if not author:
                        raise ValueError("Имя автора не должно быть пустым.")
                    break
                except ValueError as e:
                    print(e)
            comment = input("Введите комментарий: ")
            while True:
                try:
                    rating = int(input("Введите рейтинг (1-5): "))
                    if rating < 1 or rating > 5:
                        raise ValueError("Рейтинг должен быть от 1 до 5.")
                    break
                except ValueError as e:
                    print(e)
            review = Review(product_id, author, comment, rating)
            controller.add_review(product_id, review)

        elif choice == '8':
            product_id = input("Введите ID продукта для анализа отзывов: ")
            product = next((p for p in controller.products if p.product_id == product_id), None)
            if product:
                analyzer = ReviewAnalyzer(product)
                average_rating = analyzer.calculate_average_rating()
                recommendations = analyzer.provide_recommendations()
                print(f"Средний рейтинг для продукта {product.product_name}: {average_rating:.2f}")
                print("Рекомендации:")
                for recommendation in recommendations:
                    print(recommendation)
            else:
                print(f"Продукт с ID {product_id} не найден.")

        elif choice == '9':
            print("Выход из программы.")
            break

        else:
            print("Неверный выбор. Пожалуйста, попробуйте снова.")


if __name__ == "__main__":
    main()
