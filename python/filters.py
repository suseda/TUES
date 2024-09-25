def filter_by(original_dict, filter_weight, filter_height):
    filtered_dict = {}
    for key, value in original_dict.items():
        if value[0] >= filter_height and value[1] >= filter_weight:
            filtered_dict[key] = value
    return filtered_dict

def get_diff(original_dict, filtered_dict):
    diff_dict = {}
    for key, value in original_dict.items():
        if key in filtered_dict:
            pass
        else:
            diff_dict[key] = value
    return diff_dict



original_dict = {'Cierra Vega': [6.2, 70], 'Alden Cantrell': [5.9, 65], 'Kierra Gentry': [6.0, 68], 'Pierre Cox': [5.8, 66]}

filtered_dict = filter_by(original_dict, 65, 6) 
diff_dict = get_diff(original_dict, filtered_dict)
print(filtered_dict)
print(diff_dict)