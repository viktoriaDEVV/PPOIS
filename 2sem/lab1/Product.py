from Review import Review
from Certificate import *


class Product:
    _id_counter = 1

    def __init__(self, product_name: str) -> None:
        self.product_id = f"P{Product._id_counter:03}"
        self.product_name = product_name
        self.attributes = {
            "defects": "have",
            "quality": "low",
            "hygiene": "bad"
        }
        self.quality_certificates = []
        self.inspection_status = "Not passed"
        self.reviews = []
        Product._id_counter += 1

    def add_review(self, review: Review) -> None:
        self.reviews.append(review)

    def add_certificate(self, certificate: Certificate) -> None:
        self.quality_certificates.append(certificate)

    def __str__(self) -> str:
        return (f"Product(ID = {self.product_id}, Name = {self.product_name}, "
                f"Attributes = {self.attributes}, "
                f"Certificates = {len(self.quality_certificates)})")
