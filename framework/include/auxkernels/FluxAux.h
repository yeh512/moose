
#ifndef FLUXAUX_H
#define FLUXAUX_H

#include "AuxKernel.h"

// Forward Declarations
class FluxAux;

template <>
InputParameters validParams<FluxAux>();

/**
 * Auxiliary kernel responsible for computing the Darcy velocity given
 * several fluid properties and the pressure gradient.
 */
class FluxAux : public AuxKernel
{
public:
  FluxAux(const InputParameters & parameters);

protected:
  /**
   * AuxKernels MUST override computeValue.  computeValue() is called on
   * every quadrature point.  For Nodal Auxiliary variables those quadrature
   * points coincide with the nodes.
   */
  virtual Real computeValue() override;
  /// Will hold 0, 1, or 2 corresponding to x, y, or z.
  int _component;
  /// Holds the solution at current quadrature points
  const VariableValue & _u;
  /// Holds the solution gradient at the current quadrature points
  const VariableGradient & _grad_u;

  /// Holds the permeability and viscosity from the material system
  std::string _diffusivity;
  const MaterialProperty<Real> & _diffusion_coef;

};

#endif // FLUXAUX_H
