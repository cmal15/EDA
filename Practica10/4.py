def merge(left, rigth):
    result = []
    left_idx, rigth_idx = 0,0
    while left_idx < len(left) and rigth_idx < len(rigth):
        if left[left_idx] <= rigth[rigth_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(rigth[rigth_idx])
            rigth_idx += 1
    
    if left:
        result.extend(left[left_idx:])
    if rigth:
        result.extend(rigth[rigth_idx:])
    return result

def merge_sort(m):
    if len(m) <= 1:
        return m
    middle = len(m) // 2
    left = m[:middle]
    rigth = m[middle:]
    left = merge_sort(left)
    rigth = merge_sort(rigth)
    return list(merge(left,rigth))

lista1 = [4,12,87,1,32,54,36,78,90,7]
print(merge_sort(lista1))