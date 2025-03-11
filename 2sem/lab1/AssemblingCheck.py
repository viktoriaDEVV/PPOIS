from ProductionStages import *


class AssemblingCheck(ProductionStages):

    def check(self, product: 'Product') -> str:
        if product.attributes["defects"] == "none":
            return "Стадия сборки пройдена."
        else:
            return "Стадия сборки не пройдена."
