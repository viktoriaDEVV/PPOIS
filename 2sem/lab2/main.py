from model import *
from view import *

if __name__ == "__main__":
    root = Tk()
    model = Model()
    controller = Controller(model, None)
    view = View(root, controller)
    controller.view = view
    root.mainloop()
