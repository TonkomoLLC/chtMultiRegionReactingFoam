    const fvMesh& mesh = fluidRegions[i];

    combustionModels::rhoCombustionModel& reaction = reactionFluid[i];
    rhoReactionThermo& thermo = reaction.thermo();
    PtrList<volScalarField>& Y = reactionFluid[i].thermo().composition().Y(); 
    thermo.validate(args.executable(), "h", "e");

    volScalarField& rho = rhoFluid[i];
    volVectorField& U = UFluid[i];
    surfaceScalarField& phi = phiFluid[i];
    volScalarField& Qdot = QdotFluid[i];


    compressible::turbulenceModel& turb = turbulence[i];

    volScalarField& p = thermo.p();
    const volScalarField& psi = thermo.psi();

    IOMRFZoneList& MRF = MRFfluid[i];
    fv::options& fvOptions = fluidFvOptions[i];

    const dimensionedScalar initialMass
    (
        "initialMass",
        dimMass,
        initialMassFluid[i]
    );

    radiation::radiationModel& rad = radiation[i];

    const label pRefCell = pRefCellFluid[i];
    const scalar pRefValue = pRefValueFluid[i];
    const bool frozenFlow = frozenFlowFluid[i];

    volScalarField& p_rgh = p_rghFluid[i];

    const dimensionedVector& g = gFluid[i];
    const volScalarField& gh = ghFluid[i];
    const surfaceScalarField& ghf = ghfFluid[i];
    
    multivariateSurfaceInterpolationScheme<scalar>::fieldTable fields = fieldsFluid[i];
    
    basicMultiComponentMixture& composition = reactionFluid[i].thermo().composition();	
 
    const word inertSpecie(thermo.lookup("inertSpecie"));
    if (!composition.species().found(inertSpecie))
    {
        FatalIOErrorIn(args.executable().c_str(), thermo)
            << "Inert specie " << inertSpecie << " not found in available species "
            << composition.species()
            << exit(FatalIOError);
    }

    const label inertIndex(composition.species()[inertSpecie]);   
    
    const bool momentumPredictor = momentumPredictorFluid[i];

    bool& resReachedFluid = residualReachedFluid[i];
    bool& residualControlUsed = residualControlUsedFluid[i];
