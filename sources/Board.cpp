
#include <iostream>
#include "Board.hpp"

using namespace std;
using namespace pandemic;   

 map<City,vector<City>> Board::all_cities;
 map<City,Color> Board::city_by_color;

    void Board::init_map(){
        Board::all_cities[City::Algiers] = {City::Madrid ,City::Paris ,City::Istanbul, City::Cairo};
        Board::all_cities[City::Atlanta] = {City::Chicago ,City::Miami ,City::Washington};
        Board::all_cities[City::Baghdad] = {City::Tehran ,City::Istanbul ,City::Cairo ,City::Riyadh ,City::Karachi};
        Board::all_cities[City::Bangkok] = {City::Kolkata ,City::Chennai ,City::Jakarta ,City::HoChiMinhCity ,City::HongKong};
        Board::all_cities[City::Beijing] = {City::Shanghai ,City::Seoul};
        Board::all_cities[City::Bogota] = {City::MexicoCity ,City::Lima ,City::Miami ,City::SaoPaulo ,City::BuenosAires};
        Board::all_cities[City::BuenosAires] = {City::Bogota ,City::SaoPaulo};
        Board::all_cities[City::Cairo] = {City::Algiers ,City::Istanbul, City::Baghdad ,City::Khartoum ,City::Riyadh};
        Board::all_cities[City::Chennai] = {City::Mumbai ,City::Delhi ,City::Kolkata ,City::Bangkok, City::Jakarta};
        Board::all_cities[City::Chicago] = {City::SanFrancisco ,City::LosAngeles ,City::MexicoCity ,City::Atlanta ,City::Montreal};
        Board::all_cities[City::Delhi] = {City::Tehran ,City::Karachi ,City::Mumbai ,City::Chennai ,City::Kolkata};
        Board::all_cities[City::Essen] = {City::London, City::Paris, City::Milan ,City::StPetersburg};
        Board::all_cities[City::HoChiMinhCity] = {City::Jakarta ,City::Bangkok ,City::HongKong ,City::Manila};
        Board::all_cities[City::HongKong] = {City::Bangkok ,City::Kolkata ,City::HoChiMinhCity ,City::Shanghai ,City::Manila ,City::Taipei};
        Board::all_cities[City::Istanbul] = {City::Milan ,City::Algiers ,City::StPetersburg, City::Cairo ,City::Baghdad ,City::Moscow};
        Board::all_cities[City::Jakarta] = {City::Chennai ,City::Bangkok ,City::HoChiMinhCity ,City::Sydney};
        Board::all_cities[City::Johannesburg] ={City:: Kinshasa , City::Khartoum};
        Board::all_cities[City::Karachi]= {City::Tehran , City::Baghdad, City::Riyadh ,City:: Mumbai ,City::Delhi};
        Board::all_cities[City::Khartoum] = {City::Cairo, City::Lagos ,City:: Kinshasa ,City::Johannesburg};
        Board::all_cities[City::Kinshasa] = {City::Lagos ,City::Khartoum ,City::Johannesburg};
        Board::all_cities[City::Kolkata] = {City::Delhi ,City::Chennai ,City::Bangkok ,City::HongKong};
        Board::all_cities[City::Lagos] = {City::SaoPaulo, City::Khartoum ,City::Kinshasa};
        Board::all_cities[City::Lima]  = {City::MexicoCity, City::Bogota ,City::Santiago};
        Board::all_cities[City::London] = {City::NewYork ,City::Madrid ,City::Essen ,City::Paris};
        Board::all_cities[City::LosAngeles]  = {City::SanFrancisco ,City::Chicago ,City::MexicoCity, City::Sydney};
        Board::all_cities[City::Madrid]= {City::London ,City::NewYork, City::Paris, City::SaoPaulo ,City::Algiers};
        Board::all_cities[City::Manila] = {City::Taipei, City::SanFrancisco ,City::HoChiMinhCity ,City::Sydney,City::HongKong};
        Board::all_cities[City::MexicoCity]  = {City::LosAngeles, City::Chicago ,City::Miami ,City::Lima, City::Bogota};
        Board::all_cities[City::Miami] = {City::Atlanta ,City::MexicoCity, City::Washington ,City::Bogota};
        Board::all_cities[City::Milan] = {City::Essen ,City::Paris ,City::Istanbul};
        Board::all_cities[City::Montreal]= {City::Chicago, City::Washington ,City::NewYork};
        Board::all_cities[City::Moscow] = {City::StPetersburg, City::Istanbul ,City::Tehran};
        Board::all_cities[City::Mumbai]= {City::Karachi ,City::Delhi ,City::Chennai};
        Board::all_cities[City::NewYork] = {City::Montreal, City::Washington, City::London ,City::Madrid};
        Board::all_cities[City::Osaka] = {City::Taipei ,City::Tokyo};
        Board::all_cities[City::Paris] = {City::Algiers ,City::Essen ,City::Madrid, City::Milan, City::London};
        Board::all_cities[City::Riyadh] = {City::Baghdad ,City::Cairo, City::Karachi};
        Board::all_cities[City::SanFrancisco] = {City::LosAngeles ,City::Chicago ,City::Tokyo, City::Manila};
        Board::all_cities[City::Santiago]  = {City::Lima};
        Board::all_cities[City::SaoPaulo] = {City::Bogota ,City::BuenosAires, City::Lagos ,City::Madrid};
        Board::all_cities[City::Seoul] = {City::Beijing ,City::Shanghai ,City::Tokyo};
        Board::all_cities[City::Shanghai] = {City::Beijing, City::HongKong ,City::Taipei ,City::Seoul ,City::Tokyo};
        Board::all_cities[City::StPetersburg] = {City::Essen, City::Istanbul ,City::Moscow};
        Board::all_cities[City::Sydney] = {City::Jakarta ,City::Manila ,City::LosAngeles};
        Board::all_cities[City::Taipei] = {City::Shanghai ,City::HongKong, City::Osaka, City::Manila};
        Board::all_cities[City::Tehran] ={City::Baghdad ,City::Moscow ,City::Karachi ,City::Delhi};
        Board::all_cities[City::Tokyo] = {City::Seoul ,City::Shanghai ,City::Osaka ,City::SanFrancisco};
        Board::all_cities[City::Washington] = {City::Atlanta ,City::NewYork ,City::Montreal, City::Miami};

        // map of colors
        Board::city_by_color[City::Algiers] = Color::Black;
        Board::city_by_color[City::Atlanta] = Color::Blue;
        Board::city_by_color[City::Baghdad] = Color::Black;
        Board::city_by_color[City::Bangkok] = Color::Red;
        Board::city_by_color[City::Beijing] = Color::Red;
        Board::city_by_color[City::Bogota] =Color::Yellow;
        Board::city_by_color[City::BuenosAires] = Color::Yellow;
        Board::city_by_color[City::Cairo] = Color::Black;
        Board::city_by_color[City::Chennai] =Color::Black;
        Board::city_by_color[City::Chicago] = Color::Blue; 
        Board::city_by_color[City::Delhi] = Color::Black;
        Board::city_by_color[City::Essen] = Color::Blue;
        Board::city_by_color[City::HoChiMinhCity] = Color::Red;
        Board::city_by_color[City::HongKong] = Color::Red;
        Board::city_by_color[City::Istanbul] = Color::Black;
        Board::city_by_color[City::Jakarta] =Color::Red;
        Board::city_by_color[City::Johannesburg] = Color::Yellow;
        Board::city_by_color[City::Karachi]= Color::Black;
        Board::city_by_color[City::Khartoum] = Color::Yellow;
        Board::city_by_color[City::Kinshasa] = Color::Yellow;
        Board::city_by_color[City::Kolkata] = Color::Black;
        Board::city_by_color[City::Lagos] = Color::Yellow;
        Board::city_by_color[City::Lima]  = Color::Yellow;
        Board::city_by_color[City::London] = Color::Blue;
        Board::city_by_color[City::LosAngeles]  = Color::Yellow;
        Board::city_by_color[City::Madrid]= Color::Blue;
        Board::city_by_color[City::Manila] = Color::Red;
        Board::city_by_color[City::MexicoCity]  = Color::Yellow;
        Board::city_by_color[City::Miami] = Color::Yellow;
        Board::city_by_color[City::Milan] = Color::Blue;
        Board::city_by_color[City::Montreal]= Color::Blue;
        Board::city_by_color[City::Moscow] = Color::Black;
        Board::city_by_color[City::Mumbai]= Color::Black;
        Board::city_by_color[City::NewYork] = Color::Blue;
        Board::city_by_color[City::Osaka] = Color::Red;
        Board::city_by_color[City::Paris] = Color::Blue;
        Board::city_by_color[City::Riyadh] = Color::Black;
        Board::city_by_color[City::SanFrancisco] = Color::Blue;
        Board::city_by_color[City::Santiago]  = Color::Yellow;
        Board::city_by_color[City::SaoPaulo] =Color::Yellow;
        Board::city_by_color[City::Seoul] = Color::Red;
        Board::city_by_color[City::Shanghai] = Color::Red;
        Board::city_by_color[City::StPetersburg] = Color::Blue;
        Board::city_by_color[City::Sydney] = Color::Red;
        Board::city_by_color[City::Taipei] = Color::Red;
        Board::city_by_color[City::Tehran] =Color::Black;
        Board::city_by_color[City::Tokyo] = Color::Red;
        Board::city_by_color[City::Washington] = Color::Blue;
    }
    string Board::enum_to_string(City c){
        switch (c)
        {
            case City::Algiers:
                return "Algiers";
            case City::Atlanta:
                return "Atlanta";
            case City::Baghdad:
                return "Baghdad";
            case City::Bangkok:
                return "Bangkok";
            case City::Beijing:
                return "Beijing";
            case City::Bogota:
                return "Bogota"; 
            case City::BuenosAires:
                return "BuenosAires";
            case City::Cairo:
                return "Cairo";
            case City::Chennai: 
                return "Chennai";
            case City::Chicago :
                return "Chicago";
            case City::Delhi :
                return "Delhi";
            case City::Essen :  
                return "Essen";
            case City::HoChiMinhCity:
                return "HoChiMinhCity";
            case City::HongKong:
                return "HongKong";
            case City::Istanbul:
                return "Istanbul";
            case City::Jakarta: 
                return "Jakarta";
            case City::Johannesburg:
                return "Johannesburg";
            case City::Karachi:
                return "Karachi";
            case City::Khartoum:
                return "Khartoum";
            case City::Kinshasa :
                return "Kinshasa";
            case City::Kolkata :
                return "Kolkata";
            case City:: Lagos :
                return "Lagos";
            case City::Lima :
                return "Lima";
            case City::London:
                return "London";
            case City:: LosAngeles:
                return "LosAngeles";
            case City::Madrid:
                return "Madrid";
            case City:: Manila:
                return "Manila";
            case City::MexicoCity:
                return "MexicoCity";
            case City::Miami:
                return "Miami";
            case City::Milan:   
                return "Milan";
            case City::Montreal:
                return "Montreal";
            case City::Moscow:
                return "Moscow";
            case City::Mumbai:
                return "Mumbai";
            case City::NewYork:
                return "NewYork";
            case City::Osaka :
                return "Osaka";
            case City::Paris :
                return "Paris";
            case City:: Riyadh :    
                return "Riyadh";
            case City::SanFrancisco:
                return "SanFrancisco";
            case City::Santiago :
                return "Santiago";
            case City::SaoPaulo :
                return "SaoPaulo";
            case City::Seoul :
                return "Seoul";
            case City::Shanghai:
                return "Shanghai";
            case City::StPetersburg:
                return "StPetersburg";
            case City::Sydney :
                return "Sydney";
            case City::Taipei :
                return "Taipei";
            case City::Tehran :
                return "Tehran";
            case City::Tokyo :
                return "Tokyo";
            case City::Washington:
                return "Washington";

            default:
                break;
        }
    }

string print_color(Color c){
    switch (c)
    {
    case Color::Black:
        return "Black";
    case Color::Blue:
        return "Blue";
    case Color::Red:
        return "Red";
    case Color::Yellow:
        return "Yellow";
    
    default:
        break;
    }
}
  Board::Board(){
        init_map();
    }


    bool Board::is_clean(){
        for (auto& i : disease_level){
            if (i.second > 0)
            {
                return false;
            }
        }
        return true;
    }
    
    void Board ::remove_cures(){
        cure.clear();
    }

    void Board::remove_stations(){
        station.clear();
    }

    int& Board::operator[] (City city){
        return disease_level[city];
    }


    ostream& pandemic::operator<< (std::ostream& os ,const Board& x){
        os << "Disease Level:\n";
        for (auto i : x.disease_level){
            os << " City: " << Board::enum_to_string(i.first) << "  ,disease level: " << i.second << endl;
        }
        os << "\nResearch Station:\n";
        for (auto i : x.station){
            os << Board::enum_to_string(i) << endl;
        }
        os << "\nCures:\n";
        for (auto i : x.cure){
            os  << print_color(i) << endl;
        }
        return os;  
    }
    
