from QualityStandard import QualityStandard
from Certificate import Certificate
from AssemblingCheck import *
from QualityCheck import *
from PackagingCheck import *
from Review import Review


class QualityController:

    def __init__(self) -> None:
        self.products = []
        self.assembling_check = AssemblingCheck()
        self.quality_check = QualityCheck()
        self.packaging_check = PackagingCheck()

    def add_product(self, product: Product) -> None:
        self.products.append(product)

    def show_products(self) -> list[tuple[str, str]]:
        return [(product.product_id, product.product_name) for product in self.products]

    def check_compliance(self, product_id: str, quality_standard: QualityStandard) -> tuple[bool, list]:
        product = next((p for p in self.products if p.product_id == product_id), None)
        if product is None:
            print(f"Продукт с ID {product_id} не найден.")
            return False, []
        failed_criteria = []
        for criterion, required_value in quality_standard.criteria.items():
            product_value = product.attributes.get(criterion)
            print(f"Проверка критерия '{criterion}': продукт имеет '{product_value}', требуется '{required_value}'")
            if product.attributes.get(criterion) != required_value:
                failed_criteria.append(criterion)
        if failed_criteria:
            print(
                f"Продукт {product_id} не прошел проверку качества\
                 по следующим критериям: {', '.join(failed_criteria)}.")
        else:
            product.inspection_status = 'Passed'
            print(product.inspection_status)
            print(f"Продукт {product_id} прошел проверку по стандарту качества.")

        return not failed_criteria, failed_criteria

    def certify_product(self, product_id: str, quality_standard: QualityStandard) -> None:
        product = next((p for p in self.products if p.product_id == product_id), None)
        self.check_compliance(product_id, quality_standard)
        if any(cert.is_valid() and cert.quality_standard == quality_standard for cert in product.quality_certificates):
            print(f"Продукт {product.product_name} уже имеет действующий сертификат по стандарту {quality_standard}.")
            return
        if product and product.inspection_status == 'Passed':
            certificate = Certificate(product)
            product.add_certificate(certificate)
            print(f"Сертификат {certificate.certificate_id} выдан для продукта {product.product_name} "
                  f"по стандарту качeства {quality_standard.standard_name}.")
        elif product:
            print(f"Продукт {product.product_name} не прошел проверку качества и не может быть сертифицирован.")
        else:
            print(f"Продукт с ID {product_id} не найден.")

    def improve_product(self, product_id: str, quality_standard: QualityStandard) -> None:
        print(f"Поиск продукта с ID: {product_id}")
        product = next((p for p in self.products if p.product_id == product_id), None)
        if product is None:
            print(f"Продукт с ID {product_id} не найден.")
            return
        passed, failed_criteria = self.check_compliance(product_id, quality_standard)
        if not passed:
            print(f"Улучшения внесены в продукт {product.product_name}:")
            for criterion in failed_criteria:
                old_value = product.attributes.get(criterion, "Неизвестно")
                new_value = quality_standard.criteria[criterion]
                product.attributes[criterion] = new_value
                print(f"  {criterion}: улучшено с {old_value} на {new_value}")
        else:
            print(f"Продукт {product.product_name} уже соответствует стандарту качества.")

    def run_production(self, product: Product) -> None:
        print(f"Запустилась стадия сборки: {self.assembling_check.check(product)}")
        print(f"Запустилась стадия проверки качества: {self.quality_check.check(product)}")
        print(f"Запустилась стадия упаковки: {self.packaging_check.check(product)}")

    def add_review(self, product_id: str, review: Review) -> None:
        product = next((p for p in self.products if p.product_id == product_id), None)
        if product:
            product.add_review(review)
            print(f"Отзыв добавлен к продукту {product.product_name}.")
        else:
            print(f"Продукт с ID {product_id} не найден.")
