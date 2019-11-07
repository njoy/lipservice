struct Ec {
  using Value_t = double;
  static std::string name(){ return "ec"; }

  static std::string description(){ 
    return 
        "The ec argument specifies the energy (in eV) of the fast break when\n"
        "calculating a weight function.";
  }

  static bool verify( const Value_t E,
                      const Argument< Eb >& eb){ 
    return (E > 0.0) and ( E > eb.value ); 
  }
};
