from datetime import datetime


class Review:
    def __init__(self, product_id: str, author: str, comment: str, rating: int) -> None:
        self.product_id = product_id
        self.author = author
        self.comment = comment
        self.rating = rating
        self.review_date = datetime.now().date()

    def __str__(self) -> str:
        return (f"Product ID={self.product_id}, "
                f"Author={self.author}, Comment={self.comment}, "
                f"Rating={self.rating}, Date={self.review_date})")
