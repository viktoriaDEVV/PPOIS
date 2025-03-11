from ProductionStages import *


class QualityCheck(ProductionStages):
    def check(self, product: 'Product') -> str:
        if product.attributes["quality"] == "high":
            return "Стадия проверки качества пройдена."
        else:
            return "Стадия проверки качества не пройдена."
