class Rectangle():

    def __init__(self, x1=None, y1=None, x2=None, y2=None):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def is_overlap(self, rect):
        if rect.x1 > self.x2 or rect.x2 < self.x1:
            return False
        if rect.y1 > self.y2 or rect.y2 < self.y1:
            return False
        return True


def main():
    xy = Rectangle(1, 1, 2, 2)
    ab = Rectangle(2, 3, 3, 5)
    assert xy.is_overlap(ab) == False, "rectangles overlap"

    xy = Rectangle(1, 1, 2, 2)
    ab = Rectangle(1.5, 1.5, 3, 5)
    assert xy.is_overlap(ab) == True, "rectangles do notoverlap"

if __name__ == "__main__":
    main()
