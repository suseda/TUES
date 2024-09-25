name_id_dict = {'Tisho': 1,'Pesho': 2,'Mariika': 3,'Ivancho': 4,'Katinka': 5,'Borimechkata': 7,}
id_ages_dict = {1: 23,2: 15,3: 16,4: 17,5: 9,7: 18,}
id_sex_dict = {1: 'male',2: 'male',3: 'female',4: 'male',5: 'female',7: 'male',}

def classify_by_avg_age_per_sex(name_id_dict, id_age_dict, id_sex_dict):
    avg_age = calculate_avg_age_per_sex(id_sex_dict, id_age_dict)
    res = {}
    
    for key, value in name_id_dict.items():
        if id_age_dict[value] < avg_age[id_sex_dict[value]]:
            res[value] = 'below'
        elif id_age_dict[value] > avg_age[id_sex_dict[value]]:
            res[value] = 'above'
        else:
            res[value] = 'equal to'
    return res

def calculate_avg_age_per_sex(id_sex_dict, id_age_dict):
    number_of_males, number_of_females, avg_age_male, avg_age_female = 0, 0, 0, 0
    
    for key, value in id_sex_dict.items():
        if value == 'male':
            number_of_males+=1
            avg_age_male += id_age_dict[key]
        else:
            number_of_females += 1
            avg_age_female += id_age_dict[key]
    
    res = {'male': round(avg_age_male/number_of_males), 'female': round(avg_age_female / number_of_females)}
    return res

def generate_output(name_id_dict, id_sex_dict, classified, for_name):
    return for_name + "'s age is " + classified[name_id_dict[for_name]] + " the average of his sex - " + id_sex_dict[name_id_dict[for_name]] + "."

print(generate_output(name_id_dict, id_sex_dict, classify_by_avg_age_per_sex(name_id_dict, id_ages_dict, id_sex_dict), 'Katinka'))