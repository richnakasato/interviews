def has_overlap(ranges):
    """
    inputs: list of ranges -> [(1,2), (2,3), ... (7,8)]
    output: t/f depending on if range has overlap (xi.upper > xi+1.lower)
    assume: at least 2 nodes given

    insight: need to remember to sort the list, otherwise can't assume that the
             next node will overlap with the prev node (if an overlap exists)
    """
    ranges.sort(key=lamdba t: t[0])
    for idx in range(1, len(ranges)):
        if ranges[idx-1][1] > ranges[idx][0]:
            return True
    return False
