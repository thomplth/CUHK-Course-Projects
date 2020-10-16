def check_invalid(triangle):
    for i in triangle:
        if i <= 0:
            return False

    return True