# import math

# def cal(x1, y1, x2, y2, x3, y3):
#     ux = x1 - x2
#     uy = y1 - y2
#     vx = x3 - x2
#     vy = y3 - y2
#     # print(ux, uy, vx, vy)
#     if (ux==0 and uy==0) or (vx==0 and vy==0):
#         return None

#     uv = ux * vx + uy * vy
#     ul = ux**2 + uy**2
#     ull = math.sqrt(ul)
#     vl = vx**2 + vy**2
#     vll = math.sqrt(vl)
#     # print(uv, ull, vll)
#     cos = uv / ull / vll
#     # print(cos)
#     return cos

# t = int(input())
# for tt in range(t):
#     arr = list(map(int, input().split()))
#     brr = list(map(int, input().split()))
#     v = [arr, brr]
#     # print(v)

#     ans = False
#     # for i in range(2):
#     #     for j in range(2):
#     #         for k in range(2):
#     #             x1 = v[i][0]
#     #             y1 = v[i][1]
#     #             x2 = v[j][2]
#     #             y2 = v[j][3]
#     #             x3 = v[k][4]
#     #             y3 = v[k][5]
#     #             print(x1, y1, x2, y2, x3, y3)

#     #             if i==0 and j==0 and k==0:
#     #                 ans_cos = cos
#     #             elif cos==ans_cos and [x1, y1, x2, y2, x3, y3]!=v[0]:
#     #                 ans = True
#     #                 break
#     #         if ans: break
#     #     if ans: break
#     for i in range(3):
#         for j in range(3):
#             vv = v[0].copy()
#             vv[i*2] = v[1][j*2]
#             vv[i*2+1] = v[1][j*2+1]
#             # print(vv)

#             if v[0][i*2]==v[1][j*2] and v[0][i*2+1]==v[1][j*2+1]:
#                 continue

#             ang_cur = set([])
#             cos_cur = cal(v[0][2], v[0][3], v[0][0], v[0][1], v[0][4], v[0][5])
#             if cos_cur is None: continue
#             ang_cur.add(cos_cur)
#             cos_cur = cal(v[0][0], v[0][1], v[0][2], v[0][3], v[0][4], v[0][5])
#             if cos_cur is None: continue
#             ang_cur.add(cos_cur)
#             cos_cur = cal(v[0][0], v[0][1], v[0][4], v[0][5], v[0][2], v[0][3])
#             if cos_cur is None: continue
#             ang_cur.add(cos_cur)
#             # print(ang_cur)

#             ang_cal = set([])
#             cos_cal = cal(vv[2], vv[3], vv[0], vv[1], vv[4], vv[5])
#             if cos_cal is None: continue
#             ang_cal.add(cos_cal)
#             cos_cal = cal(vv[0], vv[1], vv[2], vv[3], vv[4], vv[5])
#             if cos_cal is None: continue
#             ang_cal.add(cos_cal)
#             cos_cal = cal(vv[0], vv[1], vv[4], vv[5], vv[2], vv[3])
#             if cos_cal is None: continue
#             ang_cal.add(cos_cal)
#             # print(ang_cal)

#             s = ang_cur & ang_cal
#             # print(s)
#             if s:
#                 ans = True
#                 break

#             # if i==0:
#             #     cos_cur = cal(v[0][2], v[0][3], v[0][0], v[0][1], v[0][4], v[0][5])
#             # elif i==1:
#             #     cos_cur = cal(v[0][0], v[0][1], v[0][2], v[0][3], v[0][4], v[0][5])
#             # else:
#             #     cos_cur = cal(v[0][0], v[0][1], v[0][4], v[0][5], v[0][2], v[0][3])
#             # if j==0:
#             #     cos_cal = cal(vv[2], vv[3], vv[0], vv[1], vv[4], vv[5])
#             # elif j==1:
#             #     cos_cal = cal(vv[0], vv[1], vv[2], vv[3], vv[4], vv[5])
#             # else:
#             #     cos_cal = cal(vv[0], vv[1], vv[4], vv[5], vv[2], vv[3])
#             # print(f'{i} {j} {cos_cur},{cos_cal}')
#             # print(v[0], vv)
#             # if cos_cur == cos_cal and v[0]!=vv:
#             #     ans = True
#             #     break
#         if ans: break

    
#     if ans:
#         print('Yes')
#     else:
#         print('No')
    
#     # print()


def squared_dist(x1, y1, x2, y2):
    """計算兩點距離平方"""
    return (x1 - x2) ** 2 + (y1 - y2) ** 2

def orientation(p1, p2, p3):
    """計算有向面積，用於判斷順/逆時針"""
    return (p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0])

def is_possible(tri1, tri2):
    """
    tri1、tri2分別是[(x1,y1),(x2,y2),(x3,y3)]
    檢查三邊比例＋方向
    """
    # 三邊長平方
    d1_12 = squared_dist(*tri1[0], *tri1[1])
    d1_23 = squared_dist(*tri1[1], *tri1[2])
    d1_31 = squared_dist(*tri1[2], *tri1[0])

    d2_12 = squared_dist(*tri2[0], *tri2[1])
    d2_23 = squared_dist(*tri2[1], *tri2[2])
    d2_31 = squared_dist(*tri2[2], *tri2[0])

    # 不能有零邊長（題目保證座標不同不會為零）
    # 用交叉相乘檢查比例一致
    same_shape = (d1_12 * d2_23 == d1_23 * d2_12 and
                  d1_12 * d2_31 == d1_31 * d2_12)
    if not same_shape:
        return False

    # 檢查方向
    o1 = orientation(tri1[0], tri1[1], tri1[2])
    o2 = orientation(tri2[0], tri2[1], tri2[2])
    return o1 * o2 > 0  # 同號表示同方向

def solve():
    t = int(input().strip())
    for _ in range(t):
        x1,y1,x2,y2,x3,y3 = map(int, input().split())
        xp1,yp1,xp2,yp2,xp3,yp3 = map(int, input().split())
        tri1 = [(x1,y1),(x2,y2),(x3,y3)]
        tri2 = [(xp1,yp1),(xp2,yp2),(xp3,yp3)]
        print("Yes" if is_possible(tri1,tri2) else "No")

if __name__ == "__main__":
    solve()
