import unittest
from unittest import TestCase
from main import *
from Certificate import *
from QualityStandard import QualityStandard
from AssemblingCheck import *
from PackagingCheck import *
from QualityCheck import *
from QualityController import *


class ControlProduction(TestCase):
    def setUp(self):
        self.product = Product("Coffee")
        self.certificate = Certificate(self.product)
        self.ce_standard = CEStandard()
        self.fda_standard = FDAStandard()
        self.iso_standard = ISO9001Standard()
        self.review = Review("P001", "Alice", "Great product!", 5)
        criteria = {"quality": "low", "defects": "have", "hygiene": "bad"}
        self.standard = QualityStandard("CE", criteria)
        self.controller = QualityController()
        self.controller.add_product(self.product)
        self.assembling_check = AssemblingCheck()
        self.packaging_check = PackagingCheck()
        self.quality_check = QualityCheck()
        self.analyzer = ReviewAnalyzer(self.product)
        self.product.add_review(self.review)
        self.product.add_review(Review('P001', "Mike", "Средний продукт.", 3))

    def test_initialize_ce_standard(self):
        # Проверяем, что имя стандарта правильно установлено
        self.assertEqual(self.ce_standard.standard_name, "CE")

        # Проверяем, что критерии стандарта установлены правильно
        expected_criteria_ce = {
            "quality": "high",
            "defects": "none",
            "hygiene": "excellent"
        }
        self.assertEqual(self.ce_standard.criteria, expected_criteria_ce)

    def test_initialize_fda_standard(self):
        # Проверяем, что имя стандарта правильно установлено
        self.assertEqual(self.fda_standard.standard_name, "FDA")

        # Проверяем, что критерии стандарта установлены правильно
        expected_criteria_fda = {
            "quality": "high",
            "hygiene": "excellent"
        }
        self.assertEqual(self.fda_standard.criteria, expected_criteria_fda)

    def test_initialize_iso_standard(self):
        # Проверяем, что имя стандарта правильно установлено
        self.assertEqual(self.iso_standard.standard_name, "ISO 9001")

        # Проверяем, что критерии стандарта установлены правильно
        expected_criteria_iso = {
            "quality": "high",
            "defects": "none"
        }
        self.assertEqual(self.iso_standard.criteria, expected_criteria_iso)

    def test_certificate_creation(self):
        self.assertEqual(self.certificate.product, self.product)
        self.assertTrue(self.certificate.certificate_id.startswith('CERT-'))
        self.assertEqual(self.certificate.issue_date, datetime.now().date())
        self.assertEqual(self.certificate.expiration_date, self.certificate.issue_date + timedelta(days=365))

    def test_is_valid_before_expiration(self):
        self.assertTrue(self.certificate.is_valid())

    def test_is_valid_after_expiration(self):
        # Установим дату истечения сертификата в прошлое
        self.certificate.expiration_date = datetime.now().date() - timedelta(days=1)
        self.assertFalse(self.certificate.is_valid())

    def test_str_method(self):
        expected_str = (f"Certificate(ID={self.certificate.certificate_id}, Product={self.product.product_name}, "
                        f"Issue Date={self.certificate.issue_date}, Expiration Date={self.certificate.expiration_date}) ")
        self.assertEqual(str(self.certificate), expected_str)

    def test_str_standard(self):
        expected_str = "QualityStandard(Name=CE, Criteria={'quality': 'low', 'defects': 'have', 'hygiene': 'bad'})"
        self.assertEqual(str(self.standard), expected_str)

    def test_assembling_check(self):
        expected_str = self.assembling_check.check(self.product)
        self.assertEqual(expected_str, "Стадия сборки не пройдена.")

    def test_packaging_check(self):
        expected_str = self.packaging_check.check(self.product)
        self.assertEqual(expected_str, "Стадия упаковки не пройдена.")

    def test_quality_check(self):
        expected_str = self.quality_check.check(self.product)
        self.assertEqual(expected_str, "Стадия проверки качества не пройдена.")

    def test_check_not_implemented(self):
        """Тест для проверки NotImplementedError в базовом классе."""
        stage = ProductionStages()
        with self.assertRaises(NotImplementedError) as context:
            stage.check(self.product)  # Здесь передаем None, так как метод не должен выполняться

        self.assertEqual(str(context.exception), "Метод check должен быть переопределен в подклассах.")

    def test_add_review(self):
        self.product.add_review(self.review)

        self.assertIn(self.review, self.product.reviews)
        self.assertEqual(len(self.product.reviews), 3)

    def test_add_certificate(self):
        self.product.add_certificate(self.certificate)

        self.assertIn(self.certificate, self.product.quality_certificates)
        self.assertEqual(len(self.product.quality_certificates), 1)

    def test_calculate_average_rating(self):
        average_rating = self.analyzer.calculate_average_rating()
        self.assertAlmostEqual(average_rating, 4)

    def test_classify_reviews(self):
        """Тест для классификации отзывов."""
        positive_reviews, negative_reviews = self.analyzer.classify_reviews()
        self.assertEqual(len(positive_reviews), 1)  # 5, 4, 5
        self.assertEqual(len(negative_reviews), 1)  # 3, 2

    def test_provide_recommendations(self):
        recommendations = self.analyzer.provide_recommendations()
        self.assertIn("Общие проблемы:", recommendations)
        self.assertIn(" - Средний продукт.", recommendations)
        self.assertIn("Что уже хорошо:", recommendations)
        self.assertIn(" - Great product!", recommendations)


class TestQualityController(unittest.TestCase):

    def setUp(self):
        self.controller = QualityController()
        self.product = Product("Test Product")
        self.quality_standard = QualityStandard("Test Standard", {"defects": "none", "quality": "high", "hygiene": "good"})

    def test_add_product(self):
        self.controller.add_product(self.product)
        self.assertIn((self.product.product_id, self.product.product_name), self.controller.show_products)

    def test_check_compliance_pass(self):
        self.product.attributes = {"defects": "none", "quality": "high", "hygiene": "good"}
        self.controller.add_product(self.product)
        result, failed_criteria = self.controller.check_compliance(self.product.product_id, self.quality_standard)
        self.assertTrue(result)
        self.assertEqual(failed_criteria, [])

    def test_check_compliance_fail(self):
        self.controller.add_product(self.product)
        result, failed_criteria = self.controller.check_compliance(self.product.product_id, self.quality_standard)
        self.assertFalse(result)
        self.assertIn("defects", failed_criteria)
        self.assertIn("quality", failed_criteria)
        self.assertIn("hygiene", failed_criteria)

    def test_certify_product(self):
        self.product.attributes = {"defects": "none", "quality": "high", "hygiene": "good"}
        self.controller.add_product(self.product)
        self.controller.certify_product(self.product.product_id, self.quality_standard)
        self.assertEqual(len(self.product.quality_certificates), 1)
        self.assertTrue(self.product.quality_certificates[0].is_valid())

    def test_improve_product(self):
        self.controller.add_product(self.product)
        self.controller.improve_product(self.product.product_id, self.quality_standard)
        self.assertEqual(self.product.attributes["defects"], "none")
        self.assertEqual(self.product.attributes["quality"], "high")
        self.assertEqual(self.product.attributes["hygiene"], "good")

    def test_run_production(self):
        try:
            self.controller.run_production(self.product)
        except Exception as e:
            self.fail(f"run_production raised an exception: {e}")

    def test_add_review(self):
        review = Review("P001", "Alice", "Great product!", 5)
        self.controller.add_product(self.product)
        self.controller.add_review(self.product.product_id, review)
        self.assertIn(review, self.product.reviews)
