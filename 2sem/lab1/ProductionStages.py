from Product import Product


class ProductionStages:
    def check(self, product: 'Product') -> bool:
        raise NotImplementedError("Метод check должен быть переопределен в подклассах.")
