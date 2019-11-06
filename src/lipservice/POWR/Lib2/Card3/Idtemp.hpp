struct Idtemp{
  using Value_t = double;
  static std::string name(){ return "idtemp"; }
  static std::string description(){
    return "The idtemp parameter specifies the temperature ID in Kelvin.\n"
           "The default value is 300 Kelvin.";
  }
  static Value_t defaultValue(){ return 300; }
  static bool verify( const Value_t idtemp ){
    return idtemp >= 0.0;
  }
};
