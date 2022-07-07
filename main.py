a = ['sunday', 'monday', 'sunday', 'tuesday', 'wednesday', 'monday', 'sunday']

def countDays(days: list):
    answer:{str:int} = {}

    for day in days: 
        if day in answer: 
            answer[day] = answer[day]+1
        else :
            answer[day] = 1

    return answer;


print(countDays(a))
