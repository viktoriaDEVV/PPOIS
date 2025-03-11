from datetime import datetime, timedelta


class Certificate:

    def __init__(self, product: 'Product') -> None:
        self.product = product
        self.certificate_id = f'CERT-{product.product_id}-{datetime.now().strftime("%Y%m%d%H%M%S")}'
        self.issue_date = datetime.now().date()
        self.expiration_date = self.issue_date + timedelta(days=365)
        self.quality_standard = None

    def is_valid(self) -> bool:
        today = datetime.today().date()
        return self.expiration_date >= today

    def __str__(self) -> str:
        return (f"Certificate(ID={self.certificate_id}, Product={self.product.product_name}, "
                f"Issue Date={self.issue_date}, Expiration Date={self.expiration_date}) ")
