from QualityStandard import QualityStandard


class CEStandard(QualityStandard):
    def __init__(self) -> None:
        criteria = {"defects": "none", "quality": "high", "hygiene": "excellent"}
        super().__init__("CE", criteria)
