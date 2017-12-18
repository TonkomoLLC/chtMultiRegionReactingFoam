# 18-Dec-17: chtMultiRegionFoam in the OpenFOAM-dev branch now includes chemical reactions.
The Foundation release is separate and unrelated to this repository. At some point in the future we will stop maintaining the chtMultiRegionReactingFoam repository for OpenFOAM-dev and future OpenFOAM releases.

# chtMultiRegionReactingFoam
OpenFOAM transient solver for buoyant, turbulent fluid flow and solid heat conduction with conjugate heat transfer between solid and fluid regions, plus combustion with chemical reactions.

# Notes
1. Compiles with OpenFOAM-dev (last benchmarked 17-Aug-16).
2. Release includes transient and steady state solvers (chtMultiRegionReactingFoam and chtMultiRegionSimpleReactingFoam).
3. Unsteady state solver benchmarked against DETCHEM, FLUENT and reactingFoam.

