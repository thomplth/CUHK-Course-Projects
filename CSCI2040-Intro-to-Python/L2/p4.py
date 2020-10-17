import math


def check_invalid(triangle):
    border = sum(triangle) / 2

    for i in triangle:
        if i <= 0 or i >= border:
            return True

    return False


def is_isosceles_triangle(triangle):
    if not check_invalid(triangle):
        if triangle[0] == triangle[1] or triangle[0] == triangle[2] or triangle[1] == triangle[2]:
            return True
    return False


def perimeter(triangle):
    return sum(triangle)


def area(triangle):
    s = perimeter(triangle) / 2
    return math.sqrt(s * (s - triangle[0]) * (s - triangle[1]) * (s - triangle[2]) )
