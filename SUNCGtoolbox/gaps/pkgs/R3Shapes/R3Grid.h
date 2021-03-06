// Header file for GAPS scalar grid class



// Class definition

class R3Grid {
public:
  // Constructors
  R3Grid(int xresolution = 0, int yresolution = 0, int zresolution = 0);
  R3Grid(int xresolution, int yresolution, int zresolution, const R3Box& bbox);
  R3Grid(const R3Grid& grid);
  ~R3Grid(void);

  // Grid property functions
  int NEntries(void) const;
  int XResolution(void) const;
  int YResolution(void) const;
  int ZResolution(void) const;
  int Resolution(RNDimension dim) const;
  RNScalar Sum(void) const;
  RNScalar Mean(void) const;
  RNScalar Variance(void) const;
  RNScalar StandardDeviation(void) const;
  RNScalar Maximum(void) const;
  RNScalar Minimum(void) const;
  RNInterval Range(void) const;
  RNScalar L1Norm(void) const;
  RNScalar L2Norm(void) const;
  RNScalar L2NormSquared(void) const;
  RNScalar Volume(void) const;
  int Cardinality(void) const;
  R3Box GridBox(void) const;
  R3Box WorldBox(void) const;
  R3Point GridCentroid(void) const;
  R3Point WorldCentroid(void) const;
  R3Triad GridPrincipleAxes(const R3Point *grid_centroid = NULL, RNScalar *variances = NULL) const;
  R3Triad WorldPrincipleAxes(const R3Point *world_centroid = NULL, RNScalar *variances = NULL) const;
  R2Grid *Slice(int dim, int grid_coordinate) const;

  // Transformation property functions
  const R3Affine& WorldToGridTransformation(void) const;
  const R3Affine& GridToWorldTransformation(void) const;
  RNScalar WorldToGridScaleFactor(void) const;
  RNScalar GridToWorldScaleFactor(void) const;
  RNScalar WorldSpacing(RNDimension dim) const;

  // Grid value access functions
  RNRgb RgbValue(int i, int j, int k) const;
  int LabelValue(int i, int j, int k) const;
  RNScalar GridValue(int index) const;
  RNScalar GridValue(int i, int j, int k) const;
  RNScalar GridValue(RNCoord x, RNCoord y, RNCoord z) const;
  RNScalar GridValue(const R3Point& grid_point) const;
  RNScalar WorldValue(RNCoord x, RNCoord y, RNCoord z) const;
  RNScalar WorldValue(const R3Point& world_point) const;
  RNScalar& operator()(int i, int j,int k);
  void AddRgb(int i, int j,int k,int label,RNRgb RGB);


  // Grid manipulation functions
  void Abs(void);
  void Sqrt(void);
  void Square(void);
  void Negate(void);
  void Invert(void);
  void Transpose(void);
  void Normalize(void);
  void Convolve(const RNScalar filter[3][3][3]);
  void Laplacian(void);
  void Gradient(RNDimension dim);
  void GradientMagnitude(void);
  void DetectEdges(void);
  void Dilate(RNScalar grid_distance);
  void Erode(RNScalar grid_distance);
  void Blur(RNScalar grid_sigma = 2);
  void BilateralFilter(RNLength grid_sigma = 2, RNScalar value_sigma = -1);
  void PercentileFilter(RNLength grid_radius, RNScalar percentile);
  void MinFilter(RNLength grid_radius);
  void MaxFilter(RNLength grid_radius);
  void MedianFilter(RNLength grid_radius);
  void MaskNonMinima(RNLength grid_radius = 0);
  void MaskNonMaxima(RNLength grid_radius = 0);
  void Clear(RNScalar value = 0);
  void Substitute(RNScalar old_value, RNScalar new_value);
  void Add(RNScalar value);
  void Copy(const R3Grid& grid);
  void Add(const R3Grid& grid);
  void Add(const R3Grid& grid, const R3Point& grid_position, const R3Point& filter_origin, RNScalar amplitude = 1);
  void Subtract(RNScalar value);
  void Subtract(const R3Grid& grid);
  void Multiply(RNScalar value);
  void Multiply(const R3Grid& grid);
  void Divide(RNScalar value);
  void Divide(const R3Grid& grid);
  void Pow(RNScalar exponent);
  void Mask(const R3Grid& grid);
  void Threshold(RNScalar threshold, RNScalar low, RNScalar high);
  void SignedDistanceTransform(void);
  void SquaredDistanceTransform(void);
  void Voronoi(R3Grid *squared_distance_grid = NULL);
  void Gauss(RNLength sigma = sqrt(8.0), RNBoolean square = TRUE);
  void Resample(int xres, int yres, int zres);
  void PadWithZero(int xres, int yres, int zres, int xoffset = 0, int yoffset = 0, int zoffset = 0);
  void ClusterWithMeanShift(void);
  void SetGridValue(int index, RNScalar value);
  void SetGridValue(int i, int j, int k, RNScalar value);
  void AddGridValue(int i, int j, int k, RNScalar value);
  void AddGridValueMat(int i, int j, int k,int label,RNRgb RGB, RNScalar value);

  // Arithmetic operators
  R3Grid& operator=(const R3Grid& grid);
  R3Grid& operator+=(RNScalar scale);
  R3Grid& operator+=(const R3Grid& grid);
  R3Grid& operator-=(RNScalar scale);
  R3Grid& operator-=(const R3Grid& grid);
  R3Grid& operator*=(RNScalar scale);
  R3Grid& operator*=(const R3Grid& grid);
  R3Grid& operator/=(RNScalar scale);
  R3Grid& operator/=(const R3Grid& grid);

  // Rasterization functions
  void RasterizeGridValue(int ix, int iy, int iz, RNScalar value, int operation = 0);
  void RasterizeGridValueMat(int ix, int iy, int iz, RNScalar value,int label, RNRgb RGB, int operation = 0);
  void RasterizeGridPoint(RNCoord x, RNCoord y, RNCoord z, RNScalar value, int operation = 0);
  void RasterizeWorldPoint(RNCoord x, RNCoord y, RNCoord z, RNScalar value, int operation = 0);
  void RasterizeGridPoint(const R3Point& point, RNScalar value, int operation = 0);
  void RasterizeWorldPoint(const R3Point& point, RNScalar value, int operation = 0);
  void RasterizeGridSpan(const int p1[3], const int p2[3], RNScalar value, int operation = 0);
  void RasterizeGridSpanMat(const int p1[3], const int p2[3],const double r1[3], const double r2[3], const double r3[3],const R2Point& t1, const R2Point& t2, const R2Point& t3, RNScalar value,int label, RNRgb RGB, R2Image *image, int operation = 0);
  void RasterizeGridSpan(const R3Point& p1, const R3Point& p2, RNScalar value, int operation = 0);
  void RasterizeWorldSpan(const R3Point& p1, const R3Point& p2, RNScalar value, int operation = 0);
  void RasterizeGridTriangle(const int p1[3], const int p2[3], const int p3[3], RNScalar value, int operation = 0);
  void RasterizeGridTriangle(const R3Point& p1, const R3Point& p2, const R3Point& p3, RNScalar value, int operation = 0);
  void RasterizeWorldTriangle(const R3Point& p1, const R3Point& p2, const R3Point& p3, RNScalar value, int operation = 0);
  void RasterizeGridTriangleMat(const int p1[3], const int p2[3], const int p3[3],const double w1[3], const double w2[3], const double w3[3],const R2Point& t1, const R2Point& t2, const R2Point& t3, RNScalar value,int label, RNRgb RGB, R2Image *image,int operation = 0);
  void RasterizeGridTriangleMat(const R3Point& p1, const R3Point& p2, const R3Point& p3,const R2Point& t1, const R2Point& t2, const R2Point& t3, RNScalar value,int label, RNRgb RGB, R2Image *image, int operation = 0);
  void RasterizeWorldTriangleMat(const R3Point& p1, const R3Point& p2, const R3Point& p3,const R2Point& t1, const R2Point& t2, const R2Point& t3, RNScalar value,int label, RNRgb RGB, R2Image *image, int operation = 0);
  void RasterizeGridPlane(const R3Plane& plane, RNScalar value, int operation = 0);
  void RasterizeWorldPlane(const R3Plane& plane, RNScalar value, int operation = 0);
  void RasterizeGridBox(const R3Box& box, RNScalar value, int operation = 0);
  void RasterizeGridSphere(const R3Point& center, RNLength radius, RNScalar value, RNBoolean solid = TRUE, int operation = 0);
  void RasterizeWorldSphere(const R3Point& center, RNLength radius, RNScalar value, RNBoolean solid = TRUE, int operation = 0);
RNRgb ChangeRGB(const int p[3],const double r1[3],const double r2[3],const double r3[3],const R2Point& t1,const R2Point& t2,const R2Point& t3,R2Image *image,RNRgb rgb_origin);

  // Relationship functions
  RNScalar Dot(const R3Grid& grid) const;
  RNScalar L1Distance(const R3Grid& grid) const;
  RNScalar L2Distance(const R3Grid& grid) const;
  RNScalar L2DistanceSquared(const R3Grid& grid) const;

  // Transformation manipulation functions
  void SetWorldToGridTransformation(const R3Affine& affine);
  void SetWorldToGridTransformation(const R3Box& world_box);
  void SetWorldToGridTransformation(const R3Point& world_origin, const R3Vector& world_axis1, const R3Vector& world_axis2, RNLength world_radius);

  // Transformation utility functions
  R3Point WorldPosition(const R3Point& grid_point) const;
  R3Point GridPosition(const R3Point& world_point) const;
  R3Point WorldPosition(RNCoord x, RNCoord y, RNCoord z) const;
  R3Point GridPosition(RNCoord x, RNCoord y, RNCoord z) const;

  // I/O functions
  int ReadFile(const char *filename);
  int WriteFile(const char *filename) const;
  int ReadGridFile(const char *filename);
  int ReadDelphiFile(const char *filename);
  int ReadCCP4File(const char *filename);
  int ReadInsightFile(const char *filename);
  int ReadVoxelFile(const char *filename);
  int ReadDXFile(const char *filename);
  int ReadRawFile(const char *filename);
  int ReadASCIIFile(const char *filename);
  int WriteGridFile(const char *filename) const;
  int WriteDXFile(const char *filename) const;
  int WriteTxtFile(const char *filename) const;
  int WritePDBFile(const char *filename) const;
  int WriteRawFile(const char *filename, const char *format = "Float32") const;
  int WriteASCIIFile(const char *filename) const;
  int ReadGrid(FILE *fp = NULL);
  int WriteGrid(FILE *fp = NULL) const;
  int WriteTxt(FILE *fp = NULL) const;
  int Print(FILE *fp = NULL) const;

  // Visualization functions
  void DrawIsoSurface(RNScalar isolevel) const;
  void DrawSlice(int dim, int coord) const;

  // Utility functions
  int ConnectedComponents(RNScalar isolevel = 0, int max_components = 0, int *seeds = NULL, int *sizes = NULL, int *grid_components = NULL);
  int GenerateIsoSurface(RNScalar isolevel, R3Point *points, int max_points) const;

  // Debugging functions
  const RNScalar *GridValues(void) const;
  void IndicesToIndex(int i, int j, int k, int& index);
  void IndexToIndices(int index, int& i, int& j, int& k);

public:
  // Gaussian filtering
  RNScalar GridValue(RNCoord x, RNCoord y, RNCoord z, RNLength sigma) const;
  RNScalar WorldValue(RNCoord x, RNCoord y, RNCoord z, RNLength sigma) const;
  void RasterizeGridPoint(RNCoord x, RNCoord y, RNCoord z, RNScalar value, RNLength sigma, int operation = 0);
  void RasterizeWorldPoint(RNCoord x, RNCoord y, RNCoord z, RNScalar value, RNLength sigma, int operation = 0);

private:
  R3Affine grid_to_world_transform;
  R3Affine world_to_grid_transform;
  RNScalar world_to_grid_scale_factor;
  RNScalar grid_to_world_scale_factor;
  RNScalar *grid_values;
  RNRgb *rgb_values;
  int *label_values;
  int grid_resolution[3];
  int grid_row_size;
  int grid_sheet_size;
  int grid_size;
};



// Useful constants

extern const float R3_GRID_KEEP_VALUE;

const int R3_GRID_ADD_OPERATION = 0;
const int R3_GRID_SUBTRACT_OPERATION = 1;
const int R3_GRID_REPLACE_OPERATION = 2;



// Inline functions

inline int R3Grid::
NEntries(void) const
{
  // Return total number of entries
  return grid_size;
}



inline int R3Grid::
Resolution(RNDimension dim) const
{
  // Return resolution in dimension
  assert((0 <= dim) && (dim <= 2));
  return grid_resolution[dim];
}




inline int R3Grid::
XResolution(void) const
{
  // Return resolution in X dimension
  return grid_resolution[RN_X];
}




inline int R3Grid::
YResolution(void) const
{
  // Return resolution in Y dimension
  return grid_resolution[RN_Y];
}




inline int R3Grid::
ZResolution(void) const
{
  // Return resolution in Z dimension
  return grid_resolution[RN_Z];
}



inline RNScalar R3Grid::
Sum(void) const
{
  // Return sum of all grid values
  return L1Norm();
}



inline RNScalar R3Grid::
StandardDeviation(void) const
{
  // Return standard deviation
  return sqrt(Variance());
}



inline RNScalar R3Grid::
Minimum(void) const
{
  // Return smallest value
  return Range().Min();
}



inline RNScalar R3Grid::
Maximum(void) const
{
  // Return largest value
  return Range().Max();
}



inline RNScalar R3Grid::
Mean(void) const
{
  // Return average value
  if (grid_size == 0) return 0.0;
  else return L1Norm() / grid_size;
}



inline RNScalar R3Grid::
L2Norm(void) const
{
  // Return L2 norm
  return sqrt(L2NormSquared());
}



inline RNScalar R3Grid::
Volume(void) const
{
  // Find volume of non-zero values
  RNScalar scale = grid_to_world_scale_factor;
  return Cardinality() * scale * scale * scale;
}



inline R3Box R3Grid::
GridBox(void) const
{
  // Return bounding box in grid coordinates
  return R3Box(0, 0, 0, grid_resolution[0]-1, grid_resolution[1]-1, grid_resolution[2]-1);
}



inline R3Box R3Grid::
WorldBox(void) const
{
  // Return bounding box in world coordinates
  R3Point p1(0, 0, 0);
  R3Point p2(grid_resolution[0]-1, grid_resolution[1]-1, grid_resolution[2]-1);
  return R3Box(WorldPosition(p1), WorldPosition(p2));
}



inline R3Point R3Grid::
WorldCentroid(void) const
{
  // Return centroid in world coordinates
  R3Point grid_centroid = GridCentroid();
  return WorldPosition(grid_centroid);
}



inline R3Triad R3Grid::
WorldPrincipleAxes(const R3Point *world_centroid, RNScalar *variances) const
{
  // Return principle axes in world coordinates
  R3Point grid_centroid = (world_centroid) ? GridPosition(*world_centroid) : GridCentroid();
  R3Triad axes = GridPrincipleAxes(&grid_centroid, variances);
  axes.Transform(grid_to_world_transform);
  variances[0] *= grid_to_world_scale_factor;
  variances[1] *= grid_to_world_scale_factor;
  variances[2] *= grid_to_world_scale_factor;
  return axes;
}



inline const R3Affine& R3Grid::
WorldToGridTransformation(void) const
{
  // Return transformation from world coordinates to grid coordinates
  return world_to_grid_transform;
}



inline const R3Affine& R3Grid::
GridToWorldTransformation(void) const
{
  // Return transformation from grid coordinates to world coordinates
  return grid_to_world_transform;
}



inline RNScalar R3Grid::
WorldToGridScaleFactor(void) const
{
  // Return transformation from world coordinates to grid coordinates
  return world_to_grid_scale_factor;
}



inline RNScalar R3Grid::
GridToWorldScaleFactor(void) const
{
  // Return transformation from world coordinates to grid coordinates
  return grid_to_world_scale_factor;
}



inline const RNScalar *R3Grid::
GridValues(void) const
{
  // Return pointer to grid values
  return grid_values;
}



inline RNScalar R3Grid::
GridValue(int index) const
{
  // Return value at grid point referenced by index
  assert((0 <= index) && (index < grid_size));
  return grid_values[index];
}



inline RNScalar& R3Grid::
operator()(int i, int j, int k) 
{
  // Return value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  return grid_values[k * grid_sheet_size + j * grid_row_size + i];
}

inline void R3Grid::
AddRgb(int i, int j,int k,int label, RNRgb RGB)
{
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  label_values[k * grid_sheet_size + j * grid_row_size + i] = label;
  rgb_values[k * grid_sheet_size + j * grid_row_size + i] = RGB;
}


inline RNScalar R3Grid::
GridValue(int i, int j, int k) const
{
  // Return value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  return grid_values[k * grid_sheet_size + j * grid_row_size + i];
}

inline RNRgb R3Grid::
RgbValue(int i, int j, int k) const
{
  // Return value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  return rgb_values[k * grid_sheet_size + j * grid_row_size + i];
}

inline int R3Grid::
LabelValue(int i, int j, int k) const
{
  // Return value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  return label_values[k * grid_sheet_size + j * grid_row_size + i];
}


inline RNScalar R3Grid::
GridValue(const R3Point& point) const
{
  // Return value at grid point
  return GridValue(point[0], point[1], point[2]);
}



inline RNScalar R3Grid::
WorldValue(const R3Point& point) const
{
  // Return value at world point
  return GridValue(GridPosition(point));
}



inline RNScalar R3Grid::
WorldValue(RNCoord x, RNCoord y, RNCoord z) const
{
  // Return value at world point
  return GridValue(GridPosition(x, y, z));
}



inline void R3Grid::
MinFilter(RNLength grid_radius)
{
  // Set each pixel to be min of neighborhood
  PercentileFilter(grid_radius, 0);
}



inline void R3Grid::
MaxFilter(RNLength grid_radius)
{
  // Set each pixel to be max of neighborhood
  PercentileFilter(grid_radius, 1);
}



inline void R3Grid::
MedianFilter(RNLength grid_radius)
{
  // Set each pixel to be median of neighborhood
  PercentileFilter(grid_radius, 0.5);
}



inline R3Grid& R3Grid::
operator+=(RNScalar value) 
{
  // Add value to all grid values 
  Add(value);
  return *this;
}



inline R3Grid& R3Grid::
operator+=(const R3Grid& grid) 
{
  // Add passed grid values to corresponding entries of this grid
  Add(grid);
  return *this;
}



inline R3Grid& R3Grid::
operator-=(RNScalar value) 
{
  // Subtract value from all grid values 
  Subtract(value);
  return *this;
}



inline R3Grid& R3Grid::
operator-=(const R3Grid& grid) 
{
  // Subtract passed grid values from corresponding entries of this grid
  Subtract(grid);
  return *this;
}



inline R3Grid& R3Grid::
operator*=(RNScalar value) 
{
  // Multiply grid values by value
  Multiply(value);
  return *this;
}



inline R3Grid& R3Grid::
operator*=(const R3Grid& grid) 
{
  // Multiply passed grid values by corresponding entries of this grid
  Multiply(grid);
  return *this;
}



inline R3Grid& R3Grid::
operator/=(RNScalar value) 
{
  // Divide grid values by value
  Divide(value);
  return *this;
}



inline R3Grid& R3Grid::
operator/=(const R3Grid& grid) 
{
  // Divide passed grid values by corresponding entries of this grid
  Divide(grid);
  return *this;
}



inline void R3Grid::
SetGridValue(int index, RNScalar value)
{
  // Set value at grid point
  assert((0 <= index) && (index < grid_size));
  grid_values[index] = value;
}



inline void R3Grid::
SetGridValue(int i, int j, int k, RNScalar value)
{
  // Set value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  (*this)(i, j, k) = value;
}



inline void R3Grid::
AddGridValue(int i, int j, int k, RNScalar value)
{
  // Add value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  (*this)(i, j, k) += value;
}

inline void R3Grid::
AddGridValueMat(int i, int j, int k,int label,RNRgb RGB, RNScalar value)
{
  // Add value at grid point
  assert((0 <= i) && (i < XResolution()));
  assert((0 <= j) && (j < YResolution()));
  assert((0 <= k) && (k < ZResolution()));
  AddRgb(i, j, k, label,RGB);
  (*this)(i, j, k) += value;
}



inline void R3Grid::
RasterizeGridPoint(const R3Point& point, RNScalar value, int operation)
{
  // Splat value at grid point
  RasterizeGridPoint(point[0], point[1], point[2], value, operation);
}



inline void R3Grid::
RasterizeWorldPoint(RNCoord x, RNCoord y, RNCoord z, RNScalar value, int operation)
{
  // Splat value at world point
  RasterizeGridPoint(GridPosition(x, y, z), value, operation);
}



inline void R3Grid::
RasterizeWorldPoint(const R3Point& world_point, RNScalar value, int operation)
{
  // Splat value at world point
  RasterizeGridPoint(GridPosition(world_point), value, operation);
}



inline void R3Grid::
RasterizeWorldPoint(RNCoord x, RNCoord y, RNCoord z, RNScalar value, RNScalar sigma, int operation)
{
  // Splat value at world point with Gaussian filtering
  R3Point p = GridPosition(x, y, z);
  RasterizeGridPoint(p[0], p[1], p[2], value, sigma * WorldToGridScaleFactor(), operation);
}



inline void R3Grid::
RasterizeGridSpan(const R3Point& p1, const R3Point& p2, RNScalar value, int operation)
{
  // Splat value everywhere inside grid triangle
  int i1[3] = { (int) (p1[0] + 0.5), (int) (p1[1] + 0.5), (int) (p1[2] + 0.5) };
  int i2[3] = { (int) (p2[0] + 0.5), (int) (p2[1] + 0.5), (int) (p2[2] + 0.5) };
  RasterizeGridSpan(i1, i2, value, operation);
}



inline void R3Grid::
RasterizeWorldSpan(const R3Point& p1, const R3Point& p2, RNScalar value, int operation)
{
  // Splat value everywhere inside world triangle
  RasterizeGridSpan(GridPosition(p1), GridPosition(p2), value, operation);
}



inline void R3Grid::
RasterizeGridTriangle(const R3Point& p1, const R3Point& p2, const R3Point& p3, RNScalar value, int operation)
{
  // Splat value everywhere inside grid triangle
  int i1[3] = { (int) (p1[0] + 0.5), (int) (p1[1] + 0.5), (int) (p1[2] + 0.5) };
  int i2[3] = { (int) (p2[0] + 0.5), (int) (p2[1] + 0.5), (int) (p2[2] + 0.5) };
  int i3[3] = { (int) (p3[0] + 0.5), (int) (p3[1] + 0.5), (int) (p3[2] + 0.5) };
  RasterizeGridTriangle(i1, i2, i3, value, operation);
}



inline void R3Grid::
RasterizeWorldTriangle(const R3Point& p1, const R3Point& p2, const R3Point& p3, RNScalar value, int operation)
{
  // Splat value everywhere inside world triangle
  RasterizeGridTriangle(GridPosition(p1), GridPosition(p2), GridPosition(p3), value, operation);
}

inline void R3Grid::
RasterizeGridTriangleMat(const R3Point& p1, const R3Point& p2, const R3Point& p3,const R2Point& t1, const R2Point& t2, const R2Point& t3, RNScalar value,int label, RNRgb RGB, R2Image *image, int operation)
{
  // Splat value everywhere inside grid triangle
  int i1[3] = { (int) (p1[0] + 0.5), (int) (p1[1] + 0.5), (int) (p1[2] + 0.5) };
  int i2[3] = { (int) (p2[0] + 0.5), (int) (p2[1] + 0.5), (int) (p2[2] + 0.5) };
  int i3[3] = { (int) (p3[0] + 0.5), (int) (p3[1] + 0.5), (int) (p3[2] + 0.5) };
  double w1[3] = { (double)p1[0], (double)p1[1], (double)p1[2] };
  double w2[3] = { (double)p2[0], (double)p2[1], (double)p2[2] };
  double w3[3] = { (double)p3[0], (double)p3[1], (double)p3[2] };
  double s1 = sqrt((w1[0]-w2[0])*(w1[0]-w2[0])+(w1[1]-w2[1])*(w1[1]-w2[1])+(w1[2]-w2[2])*(w1[2]-w2[2]));
  double s2 = sqrt((w1[0]-w3[0])*(w1[0]-w3[0])+(w1[1]-w3[1])*(w1[1]-w3[1])+(w1[2]-w3[2])*(w1[2]-w3[2]));
  double s3 = sqrt((w3[0]-w2[0])*(w3[0]-w2[0])+(w3[1]-w2[1])*(w3[1]-w2[1])+(w3[2]-w2[2])*(w3[2]-w2[2]));
  if (s1<s2+s3 && s2<s1+s3 && s3<s1+s2)
    RasterizeGridTriangleMat(i1, i2, i3,w1,w2,w3,t1,t2,t3, value,label, RGB, image, operation);
}



inline void R3Grid::
RasterizeWorldTriangleMat(const R3Point& p1, const R3Point& p2, const R3Point& p3,const R2Point& t1, const R2Point& t2, const R2Point& t3, RNScalar value,int label, RNRgb RGB,R2Image *image, int operation)
{
  // Splat value everywhere inside world triangle
  RasterizeGridTriangleMat(GridPosition(p1), GridPosition(p2), GridPosition(p3),t1,t2,t3,value,label, RGB, image, operation);
}



inline void R3Grid::
RasterizeWorldPlane(const R3Plane& world_plane, RNScalar value, int operation)
{
  // Splat value everywhere inside world triangle
  R3Plane grid_plane(world_plane);
  grid_plane.Transform(world_to_grid_transform);
  RasterizeGridPlane(grid_plane, value, operation);
}



inline void R3Grid::
RasterizeWorldSphere(const R3Point& center, RNLength radius, RNScalar value, RNBoolean solid, int operation)
{
  // Splat value everywhere inside world sphere
  RasterizeGridSphere(GridPosition(center), radius * WorldToGridScaleFactor(), value, solid, operation);
}



inline RNScalar R3Grid::
L2Distance(const R3Grid& grid) const
{
  // Return L2 distance between this and grid
  return sqrt(L2DistanceSquared(grid));
}



inline R3Point R3Grid::
WorldPosition(const R3Point& grid_point) const
{
  // Transform point from grid coordinates to world coordinates
  return WorldPosition(grid_point[0], grid_point[1], grid_point[2]);
}



inline R3Point R3Grid::
GridPosition(const R3Point& world_point) const
{
  // Transform point from world coordinates to grid coordinates
  return GridPosition(world_point[0], world_point[1], world_point[2]);
}



inline void R3Grid::
IndicesToIndex(int i, int j, int k, int& index)
{
  // Set index of grid value at (i, j, k) 
  index = k * grid_sheet_size + j * grid_row_size + i;
}


inline void R3Grid::
IndexToIndices(int index, int& i, int& j, int& k)
{
  // Set indices of grid value at index
  k = index / grid_sheet_size;
  j = (index - k * grid_sheet_size) / grid_row_size;
  i = index % grid_row_size;
}






