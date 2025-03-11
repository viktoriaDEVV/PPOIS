from Product import Product


class ReviewAnalyzer:
    def __init__(self, product: Product) -> None:
        self.product = product

    def calculate_average_rating(self) -> float:
        total_reviews = len(self.product.reviews)
        if total_reviews == 0:
            return 0.0
        total_rating = sum(review.rating for review in self.product.reviews)
        return total_rating / total_reviews

    def classify_reviews(self) -> tuple[list, list]:
        positive_reviews = [review for review in self.product.reviews if review.rating >= 4]
        negative_reviews = [review for review in self.product.reviews if review.rating < 4]
        return positive_reviews, negative_reviews

    def provide_recommendations(self) -> list:
        positive_reviews, negative_reviews = self.classify_reviews()
        recommendations = []
        if negative_reviews:
            common_issues = set(review.comment for review in negative_reviews)
            recommendations.append("Общие проблемы:")
            for issue in common_issues:
                recommendations.append(f" - {issue}")
        if positive_reviews:
            positive_aspects = set(review.comment for review in positive_reviews)
            recommendations.append("Что уже хорошо:")
            for aspect in positive_aspects:
                recommendations.append(f" - {aspect}")
        return recommendations
