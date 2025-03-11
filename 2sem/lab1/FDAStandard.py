from QualityStandard import QualityStandard


class FDAStandard(QualityStandard):
    def __init__(self) -> None:
        criteria = {"quality": "high", "hygiene": "excellent"}
        super().__init__("FDA", criteria)
