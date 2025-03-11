from ProductionStages import *


class PackagingCheck(ProductionStages):
    def check(self, product: 'Product') -> str:
        if product.attributes["hygiene"] == "excellent":
            return "Стадия упаковки пройдена."
        else:
            return "Стадия упаковки не пройдена."
