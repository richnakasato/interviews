def within_half(sec_, min_, hrs_):
    sec_min = abs(sec_ - min_) <= 1.0
    sec_hrs = abs(sec_ - hrs_) <= 1.0
    min_hrs = abs(min_ - hrs_) <= 1.0
    return sec_min and sec_hrs and min_hrs

def main():
    # print all times hands line up with 0.5 seconds
    # 60 ticks per sec rev
    # 3600 ticks per min rev
    # 43200 ticks per hrs rev
    for seconds in range(43200): # half a day
        sec_ = seconds%60
        min_ = seconds%3600
        hrs_ = seconds%43200
        if within_half(sec_/120.0, min_/7200.0, hrs_/86400.0):
            print("{}:{}:{}".format(hrs_%43200//3600, min_%3600//60, sec_))


if __name__ == "__main__":
    main()

