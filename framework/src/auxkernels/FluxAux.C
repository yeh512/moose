#include "FluxAux.h"

template <>
InputParameters
validParams<FluxAux>()
{
  InputParameters params = validParams<AuxKernel>();
  // Declare the options for a MooseEnum.
  // These options will be presented to the user in Peacock
  // and if something other than these options is in the input file
  // an error will be printed
  MooseEnum component("x y z");

  // Use the MooseEnum to add a parameter called "component"
  params.addRequiredParam<MooseEnum>("component", component, "The desired component of velocity.");

  params.addRequiredCoupledVar("variable",
                               "The name of the variable");
  params.addRequiredParam<std::string>(
      "diffusivity",
      "The name of the diffusivity material property that will be used in the flux computation.");
  return params;
}

  FluxAux::FluxAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    // This will automatically convert the MooseEnum to an integer
    _component(getParam<MooseEnum>("component")),

    // Get the gradient of the variable
    _u(coupledValue("variable")),
    _grad_u(coupledGradient("variable")),
    _diffusivity(parameters.get<std::string>("diffusivity")),
    _diffusion_coef(getMaterialProperty<Real>(_diffusivity))
{
}

Real
FluxAux::computeValue()
{
  return -_diffusion_coef[_qp] * _grad_u[_qp](_component);
}


