#include <iostream>
#include <limits>
#include <numeric>
#include <stdio.h>
#include <string>
#include <vector>

double mass_flow_rate(double conductance,
                   int p_in,
                   int p_out) {
    return conductance * (p_in - p_out);
}

double pres_change_rate(double bulk_mod,
                        int volume,
                        double conductance) {
    return (bulk_mod/volume)*conductance;
}

double vol_elmt_pres(double prev_vol_elmt_pres,
                     double time_delta,
                     double pres_chng_rate) {
    return prev_vol_elmt_pres + (time_delta * pres_chng_rate);
}

void print_pres_vals(double time,
                     double p1,
                     double p2) {
    printf("%6.3f: accumulator %.5f cylinder %.5f\n", time, p1, p2);
}

void print_network_chng(double time,
                        std::string event_name) {
    printf("%6.3f: event %s\n", time, event_name.c_str());
}

// shamelessly stolen from:
// https://stackoverflow.com/questions/17333/what-is-the-most-effective-way-for-float-and-double-comparison
bool compare_doubles(const double lhs,
                     const double rhs,
                     const double epsilon) {
    double diff = lhs - rhs;
    return (diff < epsilon) && (-diff < epsilon);
}

int main()
{
    const int bulk_modulus = 10;
    const double epsilon = 0.0001;

    const double delta_t = 0.001;
    //const double delta_t = 0.1;
    const double start_t = 0.0;
    const double end_t = 10.0;

    const double fill_on_t = 1.0;
    const int fill_on_cond = 1;
    const std::string fill_on_event = "fill_on";
    const double fill_off_t = 4.0;
    const int fill_off_cond = 0;
    const std::string fill_off_event = "fill_off";

    const double drain_on_t = 8.0;
    const int drain_on_cond = 1;
    const std::string drain_on_event = "drain_on";

    int v1 = 100;
    double p1 = 1000.0;
    int v2 = 1;
    double p2 = 0.0;
    //int v3 = std::numeric_limits<int>::max();
    double p3 = 0;
    int fill_cond = 0;
    int drain_cond = 0;
    std::string curr_event = "";

    for (double t=start_t; t<=end_t; t+=delta_t) {
        if (compare_doubles(t, fill_on_t, epsilon)) {
            fill_cond = fill_on_cond;
            curr_event = fill_on_event;
        }
        else if (compare_doubles(t, fill_off_t, epsilon)) {
            fill_cond = fill_off_cond;
            curr_event = fill_off_event;
        }
        else if (compare_doubles(t,drain_on_t, epsilon)) {
            drain_cond = drain_on_cond;
            curr_event = drain_on_event;
        }

        auto fill_mfr = mass_flow_rate(fill_cond, p1, p2);
        auto drain_mfr = mass_flow_rate(drain_cond, p2, p3);
        auto accu_vol = pres_change_rate(bulk_modulus,
                                         v1,
                                         (-1.0) * fill_mfr);
        auto cyln_vol = pres_change_rate(bulk_modulus,
                                         v2,
                                         fill_mfr - drain_mfr);
        p1 = vol_elmt_pres(p1, delta_t, accu_vol);
        p2 = vol_elmt_pres(p2, delta_t, cyln_vol);

        print_pres_vals(t, p1, p2);
        if (curr_event.size()) {
            print_network_chng(t, curr_event);
            curr_event = "";
        }

    }
    return 0;
}
