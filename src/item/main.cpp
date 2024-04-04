#include "Bangunan.cpp"

int main() {

    vector<pair<string, int> > materials1;
    materials1.push_back(make_pair("TEAK_WOOD", 1));
    materials1.push_back(make_pair("SANDAL_WOOD", 1));
    Bangunan bangunan1(1, 50, "SMH", "SMALL_HOUSE", materials1);

    vector<pair<string, int> > materials2;
    materials2.push_back(make_pair("ALOE_WOOD", 1));
    materials2.push_back(make_pair("IRONWOOD_WOOD", 1));
    Bangunan bangunan2(2, 70, "MDH", "MEDIUM_HOUSE", materials2);

    vector<pair<string, int> > materials3;
    materials3.push_back(make_pair("TEAK_WOOD", 2));
    materials3.push_back(make_pair("ALOE_WOOD", 1));
    materials3.push_back(make_pair("IRONWOOD_WOOD", 1));
    Bangunan bangunan3(3, 90, "LRH", "LARGE_HOUSE", materials3);

    vector<pair<string, int> > materials4;
    materials4.push_back(make_pair("TEAK_WOOD", 3));
    materials4.push_back(make_pair("ALOE_WOOD", 4));
    materials4.push_back(make_pair("IRONWOOD_WOOD", 4));
    materials4.push_back(make_pair("SANDAL_WOOD", 2));
    Bangunan bangunan4(4, 150, "HTL", "HOTEL", materials4);

    cout << "Informasi Bangunan 1:" << endl << bangunan1 << endl;
    cout << "Informasi Bangunan 2:" << endl << bangunan2 << endl;
    cout << "Informasi Bangunan 3:" << endl << bangunan3 << endl;
    cout << "Informasi Bangunan 4:" << endl << bangunan4 << endl;

    return 0;
}