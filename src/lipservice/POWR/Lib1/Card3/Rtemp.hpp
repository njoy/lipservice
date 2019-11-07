struct Rtemp{
  using Value_t = double;
  static std::string name(){ return "rtemp"; }
  static std::string description(){
    return "The rtemp parameter specifies the reference temperature in\n"
           "Kelvin.  The default value is 300 Kelvin.";
  }
  static Value_t defaultValue(){ return 300; }
  static bool verify( const Value_t rtemp ){
    return rtemp >= 0.0;
  }
};
