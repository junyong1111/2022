def solution(nums):
    get = len(nums)/2
    kind = len(list(set(nums)))
    if(get<kind):
        return get
    else:
        return kind
    answer = 0
    return answer