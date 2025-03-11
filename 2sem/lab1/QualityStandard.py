class QualityStandard:

    def __init__(self, standard_name: str, criteria: dict) -> None:
        self.standard_name = standard_name
        self.criteria = criteria

    def __str__(self) -> str:
        return f"QualityStandard(Name={self.standard_name}, Criteria={self.criteria})"
