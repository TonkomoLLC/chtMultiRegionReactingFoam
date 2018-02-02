# chtMultiRegionFoam in the OpenFOAM-dev branch now includes chemical reactions.
The Foundation release is separate and unrelated to this repository. As of 1-Feb-18, the Foundation release (OpenFOAM-dev) includes transient and steady state solver for CHT+reactions. This repository will no longer be maintained as it adds no additional features over what can be found in OpenFOAM-dev (it compiles under OpenFOAM-dev through 31-Jan-18).

# chtMultiRegionReactingFoam
OpenFOAM transient solver for buoyant, turbulent fluid flow and solid heat conduction with conjugate heat transfer between solid and fluid regions, plus combustion with chemical reactions.

# Notes
1. Compiles with OpenFOAM-dev (last benchmarked 17-Aug-16).
2. Release includes transient and steady state solvers (chtMultiRegionReactingFoam and chtMultiRegionSimpleReactingFoam).
3. Unsteady state solver benchmarked against DETCHEM, FLUENT and reactingFoam.

