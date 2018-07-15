# 问题描述 : 一维形式最近点对, 分治求解
# 复杂度: nlogn
A = [0, 1, 3, 6, 8, 10, 11, 14, 24, 27]


def solver_cross(a, mid):
    if abs(a[mid - 1] - a[mid]) < abs(a[mid] - a[mid + 1]):
        return mid - 1, abs(a[mid - 1] - a[mid])
    else:
        return mid, abs(a[mid] - a[mid + 1])


def solver(a, st, ed):
    if st == ed:
        return 0, st
    if abs(st - ed) == 1:
        return st, abs(a[st] - a[ed])
    else:
        mid = (st + ed) // 2
        left_loc, left_ans = solver(a, st, mid)
        right_loc, right_ans = solver(a, mid + 1, ed)
        cross_loc, cross_ans = solver_cross(a, mid)

        _min = min(left_ans, right_ans, cross_ans)
        if _min == left_ans:
            return left_loc, left_ans
        elif _min == right_ans:
            return right_loc, right_ans
        else:
            return cross_loc, cross_ans


ans = solver(A, 1, len(A) - 1)
print('最近点对: (', A[ans[0]], ',', A[ans[0] + 1], ') 最近点距离:', ans[1])
