from QualityStandard import QualityStandard


class ISO9001Standard(QualityStandard):
    def __init__(self) -> None:
        criteria = {"defects": "none", "quality": "high"}
        super().__init__("ISO 9001", criteria)
