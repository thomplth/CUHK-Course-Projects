import pickle


def load_data(file):
    try:
        f = open(file, 'rb')
        result = pickle.load(f)
        f.close()
        return result
    except Exception as e:
        print(e)
        print("File does not exist")


def query_following(user_name):
    user_dict = load_data("followers.pydata")
    result = 0
    for l in user_dict.values():
        if user_name in l:
            result += 1
    return result


def update():
    try:
        user_dict = load_data("followers.pydata")

        user_dict["William Smith"].append("Lorna Carrico")
        user_dict["Anne Smelcer"] = ["Christine Phillips", "Charles Mason", "Tim Lathrop"]

        f = open('followers-updated.pydata', 'wb')
        pickle.dump(user_dict, f)
        f.close()
    except Exception as e:
        print(e)
        print("File not stored")


def get_num_of_followers():
    result = load_data("followers-updated.pydata")
    for k in result.keys():
        result[k] = len(result[k])
    return result
