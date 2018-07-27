#ifndef VEC3_H
#define VEC3_H


class Vec3
{
    public:

        Vec3();
        Vec3(float x, float y, float z);
        void imprimir();

        //operações com vetores
        Vec3 operator +(const Vec3& vetor) const;
        Vec3& operator +=(const Vec3& vetor);
        Vec3 operator -(const Vec3& vetor) const;
        Vec3& operator -=(const Vec3& vertor);

        Vec3& normalizar();
        Vec3 projecao(const Vec3& vertor)const;

        //operações com escalar
        Vec3 operator *(float escalar) const;
        Vec3 operator /(float escalar) const;
        Vec3& operator *=(float escalar);
        Vec3& operator /=(float escalar);


        float modulo() const;
        float produtoEscalar(const Vec3& vetor) const;
        Vec3 produtoVetorial(const Vec3& vetor) const;
        double anguloEntreVetores(const Vec3& vetor) const;
        void setX(float x);
        void setY(float y);
        void setZ(float z);

        virtual ~Vec3();

    private:
        float x, y, z;
        float comprimento;



};

#endif // VEC3_H
