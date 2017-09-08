<!-- MOOSE Documentation Stub: Remove this when content is added. -->

# SemiconductorLinearConductivity
!syntax description /Materials/SemiconductorLinearConductivity

For Linear relationship in Steinhart Hart equation, coefficient C = 0
https://en.wikipedia.org/wiki/Electrical_resistivity_and_conductivity
$$\frac{1}{T} = A + B ln(\rho}$$
where $\rho$ is electrical resistivity, and $\sigma$ is electrical conductivity
$$\rho = 1 / \sigma$$
$$\frac{1}{T} = A - B ln \sigma$$

For conductivity data in $log \sigma vs \frac{1000}{T}$
$$\frac{1}{T} = A - B ln 10 \cdot log \sigma = A - B' log \sigma$$
$$B = B'/ln 10 $$
!syntax parameters /Materials/SemiconductorLinearConductivity

!syntax inputs /Materials/SemiconductorLinearConductivity
sh_coeff_A
sh_coeff_B

!syntax children /Materials/SemiconductorLinearConductivity
