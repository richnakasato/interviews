def within_half(sec_, min_, hrs_):
    sec_min = abs(sec_ - min_) < 1.0/120.0 # less than 1/60 is within 1 second
    sec_hrs = abs(sec_ - hrs_) < 1.0/120.0
    min_hrs = abs(min_ - hrs_) < 1.0/120.0
    return sec_min and sec_hrs and min_hrs

def main():
    # print all times hands line up with 0.5 seconds
    # 60 ticks per sec rev
    # 3600 ticks per min rev
    # 43200 ticks per hrs rev
    for seconds in range(43200): # half a day
        sec_ = seconds%60 # "amount" hand is "past" 12 position
        min_ = seconds%3600
        hrs_ = seconds%43200
        sec_frac = sec_/60.0 # fraction of part behind hand over part infront
        min_frac = min_/3600.0
        hrs_frac = hrs_/43200.0
        if within_half(sec_frac, min_frac, hrs_frac):
            print("{}:{}:{}".format(int(hrs_frac*12),
                                    int(min_frac*60),
                                    int(sec_frac*60)))


if __name__ == "__main__":
    main()

